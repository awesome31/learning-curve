# Introduction to Containers

## What are Containers?

There is no single concept of a Container, but its bunch of few features of the Linux Kernel duct-taped together.

### Why do we need Containers?

Initially we had bare metal servers. These servers were there physically in racks and we would have to install the OS on them and then install the application on top of it. The code that we wrote ran on those physical servers. Most companies do not have the capability or resources to manage these physical servers.

Then software engineers, came up with the concept of Virtual Machines, where one server can have multiple Virtual Servers running on top of it, each of them separated in terms of physical resources. This was a big step forward, but it still required a lot of resources to run the virtual machines. Then came Public Clouds (AWS, GCP, Azure). With Public Clouds, we do not have the overhead of managing the resources, its just the Operating System and drivers.

Containers are lightweight virtual machines, where we can run small processes. VM virtualize the hardware, where as containers virtualize the OS. As mentioned above, containers are created using 3 features of the Linux Kernel: chroot, namespaces and cgroups.

### Chroot

Chroot changes the root directory of the process to a different directory. This is called jailing a process. With change root, anything that is outside the root directory is not accessible to the process. This is a simple way to isolate a process from the rest of the system.

### Namespaces

Namespaces provide a way to isolate the process from the rest of the system. There are different types of namespaces:

- PID namespace: Each process has its own PID namespace.
- Mount namespace: Each process hfas its own mount namespace.
- Network namespace: Each process has its own network namespace.
- UTS namespace: Each process has its own UTS namespace.
- IPC namespace: Each process has its own IPC namespace.

### Cgroups

Cgroups is a methodology to isolate resources. It is a way to limit, account and isolate the physical resources that a process can use.

**_So, at a high level containers are just a combination of chroot, namespaces and cgroups._**

## Docker

Docker is by far the most popular tools to create and manage containers.

### Docker Images

Docker Images are pre-made templates that are used to create containers.

### Commands to interact with Docker

1. `docker ps`: List all running containers.
2. `docker run`: Create and run a container.
3. `docker exec`: Execute a command in a running container.
4. `docker run -dit alpine:3.19.1`: This will run a container in detached mode with an interactive terminal. We can run `docker exec -it laughing_jones /bin/sh` to get into the container.

Anything that docker maintains does not have a /.

### Tags

Tags are used to identify the version of the image.

`docker pull ubuntu:jammy`

## Dockerfiles

Dockerfiles are a way for us to build containers on our own. These can be used for the specific usecase that we have. It is a declarative set of statements that are used to create Docker containers. Containers should be created in such a way that they are disposable.

Docker caches the layers of the image, so if we make changes to the Dockerfile, only the layers that are affected by the changes are rebuilt.
