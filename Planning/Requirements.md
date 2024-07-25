# First assessment

The first assessment for this project is a "Requirements analysis documentation" - worth 5%

Description [here](https://nuku.wgtn.ac.nz/courses/18231/pages/plan-and-requirements-analysis?module_item_id=548280).
Submission [here](https://apps.ecs.vuw.ac.nz/submit/ENGR302/Plan_and_requirements_analysis).

## Transipmedence amplifier requirements

The goal of this project is to create a transipmedence amplifier that takes a current as input and turns that into a voltage as output, and can switch to appropriate gain values automatically via software.

The purpose of the amplifier is to turn a very small current output from a photodiode into a voltage reading in the 1V-10V range. This output necessarily has to be paired with a gain value.

### 1. Input

The device shall measure currents in the range of milliamps to nanoamps.

The sensor input shall be a 50-ohm BNC connector.

The device shall have a DC Barrel Connector for providing power to the internal components.

The voltage of this input shall be researched to find the required voltage of the internal components.

### 2. Output

The output of the device shall be an analogue voltage in the range of 1V to 10V. Optionally, having a sensitivity of 0.1V.

The device shall output the standard deviation or variance of the reading.

The analogue voltage output shall be provided via a 50-ohm BNC connector.

### 3. Gain switching

The device shall switch gain values for the amplifier without physical interaction.

The device shall have a microcontroller capable of switching gain values using its addressable I/O as dictated by communication with said microcontroller.

### 4. Gain display

The gain used to output the voltage shall to be available to the user.
This can be either by: a) a physical display like an LCD, b) sent to the user via software, or both of the above.

### 5. Usage considerations

The amplifier shall emit the minimal possible amount of light to carry out its core functions. This means there shall be no sources of light in the design that are not entirely disabled during use, and that any uncovered materials should be as matte as possible.

### 6. Physical Dimensions

The physical dimensions of the device are not important, within reason. Basically it should be able to be moved between labs and tables without too much effort or take up too much space on a lab bench.
