FROM ubuntu:latest AS base

RUN apt-get update
# RUN apt-get install -y python-is-python3 python3-pip python3-pycryptodome python3-willow vim nano emacs
RUN apt-get install -y python-is-python3 python3-pip python3-venv vim nano emacs

WORKDIR /home/ubuntu/
USER ubuntu
RUN mkdir labs
RUN mkdir solutions
RUN mkdir resources
RUN mkdir results

FROM base AS crypto_labs_image

WORKDIR /home/ubuntu/
USER ubuntu

COPY --chown=ubuntu:ubuntu ./labs/* ./labs/
COPY --chown=ubuntu:ubuntu ./solutions/* ./solutions/
COPY --chown=ubuntu:ubuntu ./resources/* ./resources/
COPY --chown=ubuntu:ubuntu ./README.md ./
COPY --chown=ubuntu:ubuntu ./requirements.txt ./
WORKDIR /home/ubuntu/labs
RUN ln -s ../results results
RUN ln -s ../resources resources
WORKDIR /home/ubuntu/solutions
RUN ln -s ../results results
RUN ln -s ../resources resources
WORKDIR /home/ubuntu/

RUN python -m venv .venv
ENV PATH="/home/ubuntu/.venv/bin:$PATH"
RUN pip install -r requirements.txt

ENTRYPOINT [ "sleep", "99999" ]
