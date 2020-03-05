# Machinekit with Debian Stretch on the BeagleBone Black (BBB)

The image of BBB Machinekit Image with Debian Stretch found in this [link](https://elinux.org/Beagleboard:BeagleBoneBlack_Debian#BBW.2FBBB_.28All_Revs.29_Machinekit)  and this [link](https://drive.google.com/drive/folders/1BwDJXSf-Y5cEM5pBqkQ85MlfUg58kM9M) (private drive) is the debian image as described in this [tutorial](https://machinekoder.com/machinekit-debian-stretch-beaglebone-black/) for the installation of ROS in the BBB.

## Installation of ROS

To install ROS in the BBB with this image follow hits [tutorial](https://machinekoder.com/ros-with-debian-stretch-on-the-beaglebone-black-green-blue/).

# Accessing the BBB for the first time

To access the BBB from a terminal do:

```
ssh machinekit@192.168.7.2
```

or

```
ssh machinekit@192.168.6.2
```

And insert the password "machinekit". The machinekit before the @ in "ssh machinekit@192.168.7.2" is the username. For de "debian" username the password shold be "temppwd" and you can access the user by:

```
ssh debian@192.168.7.2
```

or

```
ssh debian@192.168.6.2
```

# Set Wi-Fi on BBB

To set a Wi-Fi connection on BBB follow this [tutorial](https://www.digikey.com/en/maker/blogs/2017/how-to-setup-wifi-on-the-beaglebone-black-wireless).