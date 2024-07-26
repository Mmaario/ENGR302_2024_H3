# Plan and Requirements analysis - H3

The first assessment for this project is a "Requirements analysis documentation" - worth 5%

Description [here](https://nuku.wgtn.ac.nz/courses/18231/pages/plan-and-requirements-analysis?module_item_id=548280).
Submission [here](https://apps.ecs.vuw.ac.nz/submit/ENGR302/Plan_and_requirements_analysis).

## Transipmedence amplifier

The goal of this project is to create a transipmedence amplifier that takes a current as input and turns that into a voltage as output, where the gain is set through software.

The purpose of the amplifier is to turn a very small current output from a photodiode into a voltage reading in the 1V-10V range. This output necessarily has to be paired with a gain value.

### Requirements

These requirements have been scaled in terms of complexity and priority as indicated by their P and C scores. P1 is the defined as being required for the core functionality of the device, P2 is defined as something the project should have or be able to do, and P3 is defined as a nice to have addition to the project.
The complexity defined as C1 taking 1 hour, C2 taking up to 10 hours per week, and C3 being in excess of this.

#### 1. Input

1.1 The device shall measure currents in the range of milliamps to nanoamps. P1 C3

1.2 The sensor input shall be a 50-ohm BNC connector. P2 C1

1.3 The device shall have a DC Barrel Connector for providing power to the internal components. P3 C1

1.4 The voltage of this input shall be researched to find the required voltage of the internal components. P1 C2

#### 2. Output

2.1 The output of the device shall be an analogue voltage in the range of 1V to 10V. Optionally, having a resolution of 0.1V. P1 C3

2.2 The device shall output the current gain setting to both:

2.2.1 The software User Interface. P1 C1

2.2.2 A display mounted on the device. P3 C2

2.3 The analogue voltage output shall be provided via a 50-ohm BNC connector. P2 C1

#### 3. Gain switching

3.1 The device shall switch gain values for the amplifier without requiring physical interaction. P1 C3

3.2 The switching of gains will be completed by a microcontroller. P1 C2

3.3 The microcontroller shall be capable of interacting with the software User Interface. P1 C3

#### 4. Usage considerations

4.1 The amplifier will need to be used in a low light environment. This means:

4.1.1 There shall be no sources of light in the design that are not entirely disabled, or disableable, during use. P2 C1

4.1.2 Any uncovered materials shall be matte. P2 C1

#### 5. Physical Dimensions

5.1 The device shall fit on a lab desk and be liftable with one hand. P3 C1

## Plan

Work will be done in stages

### Planning

Gather and record the client requirements and develop a requirements document (above). This should be completed be the end of week 3, but will likely be continually adapted as the project continues.

Design a circuit based on the requirements document over weeks 4-6. This will also involve selecting components and testing those components in discrete parts of the final circuit.

### Prototyping

Once we have a design of the entire circuit, build it over weeks 7-9.

### Testing

While building the prototype circuit, continually test it against the requirements. This will involve applying the expected currents in req 1.1. Measuring if the outputted voltages are between 1V-10V as in req 2.1. Perform a number of these tests to find a mean and variance for req 2.2.

Requirements 3.1 & 3.2 will be tested by interacting with the prototype in the way the client will use it and measuring the outcomes.

Testing will be performed during and after construction of the prototype (and subsequent versions) spanning weeks 8-11.

Closing
