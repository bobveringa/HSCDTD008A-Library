# HSCDTD008A Library

This is a library for the HSCDTD008A geomagnetic sensor by Alps Alpine.

It is one of the cheapest geomagnetic / magneto sensors available and seems to be good enough for many home projects. However, no drivers seem to be available for this chip.

## Currently supported features


| Feature | Arduino | C Driver |
|--|--|--|
| Sensor initialization | ✔️ | ✔️ |
| Stand-by mode| ✔️ | ✔️  |
| Measurement Force State | ✔️ | ✔️ |
| Measurement Normal State<sup>1</sup> | ✔️ | ✔️ |
| Temperature compensation | ✔️ | ✔️ |
| Offset calibration | ✔️ | ✔️ |
| Data Ready Pin| ✔️ | ✔️  |
| Offset Drift | ✔️ | ✔️  |
| Self test| ✔️ | ✔️  |
| FIFO | ❌ | ❌<sup>2</sup> |
| Soft reset| ✔️ | ✔️  |
| Data Resolution<sup>3</sup>| ❌ | ❌ |

1 - Normal state allows the user to read sensor data without explicitly calling start_measurement  
2 - The driver does define functions to configure FIFO configuration. However, more work is needed to properly support it.  
3 - Driver is hard-coded to use 15bit resolution  


# Design
This driver is written in C, with a wrapper for C++ so that it can be used in Arduino projects. The reason for this is that with many projects I have worked on in the past, only C++ drivers were available. This is fine for just Arduino projects, but whenever you are working on a C project, it can be quite frustrating if there is no C driver you can use as an example.

For this reason, all logic operations are implemented in C, with the C++ layer only changing up the interface, but not implementing any logic. The goal is to keep this separation even for features added in the future.

In `platform.h`functions are defined for I2C communication as well as for system sleep. This allows the driver to be used on non Arduino platforms.
