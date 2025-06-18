# ACE Week 1 Cryptography Lecture Labs
The labs are located in the "labs" directory.  There are bonus labs in there, but the main ones you need all start with "lab".  Solutions are in the "solutions" directory, but please only look there if you and the rest of your group are stuck.  My expectation, if you need to look at the solutions, is that you do not blindly copy the solution into the lab.  The rule of thumb that I used in my Masters course in similar situations that I like is that you should not have the solution and the lab up at the same time.  You should take the time to look at the solution, understand what it is doing, and then go back to the lab and write your code based on your new understanding.  I can't enforce this, so please do what works best for you to actually understand the material.

## Python development environment
We are providing multiple methods of running these labs.  If you are comfortable with Python development environments, then feel free to do what you want.  The required packages are in requirements.txt.

If you do not want to use Docker, keep in mind that your chosen development environment may lead to errors that I cannot help you fix in a timely manner.  If you want to test whether the issue is due to your environment or your code, run the solution for the lab and see if there is an issue with the solution, because all of those are tested and run correctly in the Docker container.

Setup:
```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

## Docker text-based development environment
If you are less comfortable with development environments, we are providing a few ways to use one that we have tested, providing a consistent environment.  If you are comfortable with command line, you can run the container with the below commands and then access the container:

```bash
docker load -i crypto_lab.tar
docker-compose up
docker ps
docker exec -it <container_id from ps> /bin/bash
```

The container has vim, emacs, and nano installed as text editors.

## Docker VSCode development environment
Alternatively, we also have instructions to access the labs in the container from VSCode.

First, search for and install the "Dev Containers" package in VSCode.

From a terminal run:
```bash
docker load -i crypto_lab.tar
docker-compose up
```

Then, go to the "Remote Explorer" tab in VSCode on the left.  The now running container should appear in the menu that pops up.  Click on it and open it.  Then in the new menu on the left, open a folder and pick /home/ubuntu.  You are now editing the code inside the container.

## Rebuilding Docker container
You should not need this command, but we are offering it if you feel you do.
```bash
docker build -t crypto_labs .
```

