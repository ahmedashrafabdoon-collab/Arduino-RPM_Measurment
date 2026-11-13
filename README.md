# RPM Measurement Using IR Encoder Sensor and Arduino

## Overview

This project measures the rotational speed of an encoder disc using an IR sensor and an Arduino.

The IR sensor detects the slots on the rotating encoder disc and generates pulses. Arduino counts these pulses using hardware interrupts and calculates the rotational speed in Revolutions Per Minute (RPM).

The RPM value is continuously displayed through the Serial Monitor.

**Note:** The measured RPM represents the rotation speed of the encoder disc, not the actual wheel RPM. No gear ratio or wheel-to-encoder conversion is applied.

## Components Used

- Arduino board
- IR Encoder Sensor (LM393-based)
- Encoder Disc
- DC Geared Motor
- Connecting Wires

## How It Works

1. The encoder disc rotates with the motor.
2. The IR sensor detects the slots in the disc.
3. Each detected slot generates a pulse.
4. Arduino uses a hardware interrupt to count incoming pulses.
5. The number of pulses is used to calculate the RPM over a fixed time interval.
6. The calculated RPM is printed to the Serial Monitor.

## RPM Calculation

The RPM is calculated using the following formula:

$$
RPM = \frac{Pulses \times 60}{PPR \times \Delta t}
$$

Where:

- `Pulses`: Number of detected pulses during the measurement interval.
- `PPR`: Number of pulses per encoder disc revolution.
- `Δt`: Measurement interval in seconds.
- `60`: Converts revolutions per second into revolutions per minute.

## Key Concepts

- Hardware Interrupts
- Pulse Counting
- Encoder Sensors
- RPM Measurement
- Time-Based Calculations
- Arduino Programming

## Applications

This measurement technique is useful in:

- DC motor speed monitoring.
- Robotics and mobile robots.
- Motor feedback systems.
- Closed-loop speed control.
- PID motor speed control projects.

## Future Improvements

- Implement closed-loop motor speed control using PID.
- Compare measured RPM with a target speed.
- Use encoder feedback for precise motor control.



