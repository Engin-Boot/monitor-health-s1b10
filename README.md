# Healthcare Telemetry

Case study by Anurag Thakur and Kavya KA

Understand the data packets and communication configuration
from the protocol document of the Device.
Data packet will include patient vital information (measurement, setting, mode).

Deliverables

- Application to read data (patient vitals) from generic simulator, acting as a device.
It will read device data through a virtual COM port.
Parse the data based on device protocol document.
- Application to display the parsed data on a web UI, which is accessible remotely.
 
The development happens in two segments.

## [Segment 1] COM port reader and Data parser

Setup a virtual COM port and a simulator behind it.
Implement a program that reads from the COM port and parses the data.

The parser needs to be testable without needing the simulator,
without manual checks.

## [Segment 2] Application to display real-time data on a web UI

Use python with [streamlit](https://docs.streamlit.io/en/stable/)
to show the data.
