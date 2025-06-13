#!/bin/bash

# Check if Docker is installed
if ! command -v docker &> /dev/null; then
    echo "Docker is not installed. Please install Docker first."
    exit 1
fi

# Check if running with sudo or as root
if [ "$EUID" -ne 0 ]; then
    echo "Please run this script with sudo."
    exit 1
fi

chmod 777 ./results

# Get the directory of the Dockerfile (assuming it's in the current directory)
DOCKER_DIR="$(pwd)"

# Optional: Name for the image and container (change as needed)
IMAGE_NAME="crypto-image"
CONTAINER_NAME="crypto-container"

# Check if the container is already running
if docker ps --format '{{.Names}}' | grep -q "^${CONTAINER_NAME}$"; then
    echo "Container ${CONTAINER_NAME} is already running. Using existing container."
    CONTAINER_ID=$(docker ps --filter "name=${CONTAINER_NAME}" --format '{{.ID}}')
else
    # Check if the container exists but is not running
    if docker ps -a --format '{{.Names}}' | grep -q "^${CONTAINER_NAME}$"; then
        echo "Container ${CONTAINER_NAME} exists but is not running. Starting it..."
        docker start ${CONTAINER_NAME}
        CONTAINER_ID=${CONTAINER_NAME}
    else
        # Container doesn't exist, build image and create container
        echo "Building Docker image..."
        docker build -t $IMAGE_NAME $DOCKER_DIR

        if [ $? -ne 0 ]; then
            echo "Docker build failed."
            exit 1
        fi

        echo "Running Docker container..."
        # Run the container in detached mode with volume mounts for local development
        CONTAINER_ID=$(docker run -d --name $CONTAINER_NAME \
            -v "$(pwd)/labs:/home/ubuntu/labs" \
            -v "$(pwd)/resources:/home/ubuntu/resources" \
            -v "$(pwd)/results:/home/ubuntu/results" \
            -v "$(pwd)/solutions:/home/ubuntu/solutions" \
            -v "$(pwd)/advanced_labs:/home/ubuntu/advanced_labs" \
            -u $(id -u):$(id -g) \
            $IMAGE_NAME)

        if [ $? -ne 0 ]; then
            echo "Failed to run Docker container."
            exit 1
        fi
    fi
fi

echo "Container is running with ID: $CONTAINER_ID"

# Open an interactive terminal to the container
echo "Opening terminal to the container..."
docker exec -it $CONTAINER_NAME /bin/bash