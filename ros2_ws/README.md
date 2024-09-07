# ROS Workstation (for running on your Libre Computer)

## Build Instructions

1. Ensure ROS2 Humble Hawksbill is installed on your machine.
2. Open this folder in a command prompt.
3. Run `colcon build`. The output should look something like as follows:

```
Starting >>> pico_relay
--- stderr: pico_relay                   
/usr/lib/python3/dist-packages/setuptools/command/install.py:34: SetuptoolsDeprecationWarning: setup.py install is deprecated. Use build and pip and other standards-based tools.
  warnings.warn(
---
Finished <<< pico_relay [1.21s]

Summary: 1 package finished [1.47s]
  1 package had stderr output: pico_relay
```

## Run Instructions

1. Make sure you have followed the build instructions without errors.
2. Open this folder in a command prompt.
3. Run `source install/setup.bash`.
4. Run `ros2 run pico_relay relay`.
  When running the node, ensure you don't have Arduino IDE or PlatformIO accessing the pico via a "serial monitor".
  This will occupy the port and the relay will not be able to find the pico. Close the serial monitor or the application.
