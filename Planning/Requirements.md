# First assesment

The first assesment for this project is a "Requirements analysis documentation" - worth 5%

Description [here](https://nuku.wgtn.ac.nz/courses/18231/pages/plan-and-requirements-analysis?module_item_id=548280).
Submission [here](https://apps.ecs.vuw.ac.nz/submit/ENGR302/Plan_and_requirements_analysis).

## Transipmedence amplifier requirements

The goal of this project is to create a transimpedence amplifier that takes a current as input and turns that into a voltage as output, and can switch to appropriate gain values automatically via software.

The purpose of the amplifier is to turn a very small current output from a photodiode into a voltage reading in the 1V-10V range. This output necessarily has to be paired with a gain value.


### 1. Input

The device needs to be able to measure currents in the range of milliamps to nanoamps.

### 2. Output

The output of the device needs to be an analogue voltage in the rang of 1V to 10V. Optionally, having a sensitivity of 0.1V.

Some kind of standard deviation or variance of the reading should also be displayed.

### 3. Gain switching

The gain used to output a voltage specified by requirement 2 should be selected automatically by microcontroller.

### 4. Gain display

The gain used to output the voltage should to be available to the user.
This can be either by: a) a physical display like an LCD, b) sent to the user via software, or both of the above.

### 5. Usage considerations

The use of this amplifier requires as minimal light as possible. This means there are to be no sources of light in the design that are not entirely disabled during use, and that any uncovered materials should be as matte as possible, ie not shiny.

### 6. Physical Dimensions

The physical dimensions of the device are not important, within reason. Basically it should be able to be moved between labs and tables without too much effort or take up too much space on a lab bench.

### 7. Connectors

The connectors for input and output should be designed for 50 ohm BNC cables.