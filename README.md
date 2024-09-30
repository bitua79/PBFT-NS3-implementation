# PBFT-NS3-implementation
## Overview
This project simulates the Practical Byzantine Fault Tolerance (PBFT) algorithm using the NS3 network simulator. It aims to provide insights into the performance and behavior of PBFT in distributed systems. This project was developed as the final project for the Blockchain course.

## Installation
#### 1. Follow the NS3 installation guide [here](https://www.nsnam.org/docs/release/3.29/tutorial/html/getting-started.html).
#### 2. Clone this repository:
   ```bash
   git clone https://github.com/bitua79/PBFT-NS3-implementation.git
   ```

#### 3. After cloning this repository, follow these steps to integrate the simulation files into the NS3 environment:

#### Step 1: Navigate to the NS3 Installation Directory
- First, locate your NS3 installation directory. This is typically the folder where NS3 was installed using `bake` or from source.

#### Step2: Copy the Simulation Files into the ns3 installation directory: 

- Move the project files from this repository to the corresponding folders within your NS3 installation. For example, you can use the following commands (replace `ns-3.40` with your version, and `path/to/ns3/bake` with the path of the installed ns3 `bake` folder):
```
cp -r scratch/pbft-simulator.cc /path/to/ns3/bake/source/ns-3.40/scratch
```
```
cp -r src/applications/helper/* /path/to/ns3/bake/source/ns-3.40/src/applications/helper
```
```
cp -r src/applications/model/* /path/to/ns3/bake/source/ns-3.40/src/applications/model
```

## Usage
To run the simulation, navigate to 'scratch' folder and execute:

```bash
./ns3 run scratch/blockchain-simulator.cc
```

## Collaborators
This project is a collaborative effort. Special thanks to:

- Ghazal Seyednozadi [Github](https://github.com/gnozadi)
- Ailin Hasanpour [Github](https://github.com/AilinHasanpour)

## Acknowledgments
I would like to express my gratitude to our professors and dear teaching assistant:

- Professor Mohammad Allahbakhsh [Website](http://prof.um.ac.ir/allahbakhsh/) for their guidance.
- Professor Haleh Amintoosi [Website](http://prof.um.ac.ir/amintoosi/) for their insights.
- Sadegh Sobhani [Github](github.com/SadeghSohani) for template files.

