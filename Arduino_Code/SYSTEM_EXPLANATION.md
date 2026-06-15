# Control Logic Overview

The machine operates using a pick-and-place sequence:

1. Lift planting mechanism
2. Move to seedling position
3. Lower mechanism
4. Grab seedling
5. Lift mechanism
6. Return to planting position
7. Lower mechanism
8. Release seedling

The sequence is repeated for multiple planting locations.

Hardware:
- Arduino Mega
- TB6600 Drivers
- NEMA17 Stepper Motors
- Dc Worm Gear Motor
- BTS7960 Motor Driver
- Step Down Converter
- Buck Converters x2
- Limit Switch Sensors

Author:
Nafis Devtale
Electronics Team Lead
SAEINDIA TIFAN Project
