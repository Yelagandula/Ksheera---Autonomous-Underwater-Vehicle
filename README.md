# Ksheera---Autonomous-Underwater-Vehicle
Ksheera a fleet of Autonomous Underwater Vehicles 

1. PROBLEM STATEMENT :                                                                                                                                                                                                                                        
Three fourth of the land is covered with water and water is the main resource and energy for human civilization. Water resources are spread over the ocean, sea, river, small catchment area, ponds, lakes, etc. They are used for agriculture, aquatic elements, water minerals, drinking water, industries, home use and there are no areas where water is not required. The livelihood of a huge number of people depends on water resources. A bot is proposed to carry out the work. The bot can easily move around the water surface as well as under the water. It has the major functional units like 
a) automated self-propelled underwater/ surface vehicle (ASPUW/S). 
b) Sample collection system
c) Measurement system
d) Location mapping system through GPS.
e) Communication to the cloud through network 
Following are operational steps.
a)	Initially the bot is placed on the surface of the water bed. It can be programmed for a given area of interest and also sampling point. The area of interest can be square or round shape.
b)	Once initiated to start, bot takes the GPS data to mark its current location.
c)	Bot moves on surface and reach to the designated point.
d)	It moves down by water intake and increasing the mass.
e)	It takes the sample once stable . 
f)	Perform measurement of sample. Store data.
g)	It releases water to reduce the mass. It can come up.
h)	It can transfer the measured data through the communication post. 
i)	It stores some sample  and release majority.
j)	Clean the sample store place.
k)	Mark the current location 
l)	Proceed to the next location.
m)	Repeat steps (d) to (l).
n)	Arrives back to the initial point.
o)	At the docking point entire data can be transferred to the ground system. Samples are collected for lab investigation for detailed study.
p)	At docking point it charge the battery and get ready for further operation. 

Natural water is pollution-free and is clean water. However, due to different manmade pollution and also pollution created due to natural disaster, etc. makes the water dirty. At the same time, the fish excretion in water becomes a problem for their existence. The temperature variation in water also affects the existence of aquatic species.  Further, there are many undiscovered resources like minerals are existing in the ocean and seawater. A list of parameters monitored to check the quality of water is listed in appendix-1. Parameters such as pH, turbidity, residual chlorine, and temperature are monitored to check the quality of water.
It has been a challenge to cover a wide area water network for surveillance of water quality and the existence of various water resources reaching several benefits to the stakeholder. 
2. CURRENT METHOD 
Requires planning to cover the water network. Ganga water cleaning is a task initiated by the govt. of India is one such work. Several zones are distributed all over the country. Concerned authorities move people for sample collection and brought them back to the laboratory for testing. But the timeline may not need sample validity duration. This is also true for the sea and ocean. Fisherman goes around the sea to locate the right type of fish and sometimes comes back with an empty hand. There are some boats with instrumentation that patrols the specific area and collects the sample. Samples are further tested at a laboratory. There are boat-based systems reported from china, japan, etc. These systems are instrumented with GPS, communication system and sample collection system, and measurement system. They do the measurement at the surface level. But, the majority of parameters are required to monitor at 3 to 6 feet depth.
3. LIMITATION
Almost all systems are human-operated and are destined for a specific area. They can not go inside the water and collect samples. In-situ monitoring of parameters and transferring them to a base station is also difficult. 
4. PROPOSED WORK 

5. Conceptual Design
	A conceptual design is carried by the student's group. From the functional point of view, there are the following subsystems.
5.1.	Design of ASPUW/S
The design is made such that the bot can move inside and on the surface of the water. 
 The bot is equipped with four thrusters two present on sides for the movement of the bot to move on the x and y-axis and for the movement on the z-axis the bot uses the concept of neutral buoyancy to move wherein there are two chambers present within the robot. The two chambers are equipped with  2 pumps which taken water for the moment of the bot in the negative Z-direction and attains neutral buoyancy with the amount of water taken in,  making the mass of the robot equal as to the water and remains stable at that position at a depth of 3 to 6 feet, for the movement in the positive Z direction, the bot expel out the water which was taken in earlier making the bot lighter than the water to move towards the surface of the water. A CAD model of the system is shown in Fig. 1.



![image](https://github.com/user-attachments/assets/a4adcfac-2103-4649-bda9-98fdba76028e)

 There are 2 more thrusters present on the bot which takes in information from the   Gyroscope and accelerometer for maintaining the trajectory of the robot and attenuating the disturbances caused in the water body, thus making the robot complete the trajectory without changing initial and final mapped points.


5.2	Collection of data:
    Collection of data shall take place while the bot is present inside the water body where neutral buoyancy has been achieved the robot then covers the entire trajectory inside the water body itself taking the samples at different locations or different time intervals as assigned earlier. The chamber is shown in fig2. 
It has multiple compartments. One is the large compartment where water at the given point is sucked in. Sensors are also placed in this compartment to check the water quality. It is proposed to check six parameters which include dissolved oxygen, ammonia content, salinity value, pH of the water, the pressure at that point, the temperature of the water at that point of time. The sensor data is analyzed and logged in memory. 
![image](https://github.com/user-attachments/assets/ce737634-e99e-4f7d-a734-9f355b2364da)
Fig 2: Data storage chambers

The big chamber is connected to multiple smaller chambers below it where the portion of samples is stored as per location geometry. Once the measurement is over, a small solenoid valve is opened to pass water to the bottom chamber. Further, this valve is closed and the remaining water is drained out. It does a similar action in each point and every point water samples, as well as corresponding data, are stored at their respective places. 
The bot comes up and transfers this data through the LoRA communication link to the post. It marks the data with GPS. The Sensor data and collected samples are collected at the shore after the completion of the journey of the bot.

5.3 The trajectory:

    The trajectory is chosen to have either a rectangular path or a circular path. The robot starts from a point where a predefined location is sent to the robot, and it starts moving from that point completing a full rectangle or a circular path and collecting the data at the same time at different intervals of the time under the water. Once the trajectory is completed the bot automatically floats over the surface and comes back to the starting location. A control algorithm will be developed to provide the required turns at different points to cover the entire area..

5.4	The sensors:
Two types are sensors are used.
a)	Control sensors
b)	Measurement sensors for water quality check
Control sensors are Gyroscope and accelerometers give rate and position parameters for maintaining the trajectory and vehicle stability. The position data is also updated by GPS. 
Measurement sensors  are used for dissolved oxygen levels, salinity level,  pH levels ,ammonia content, temperature of the water and  pressure at the point.

5.5 The Computation element:
A RASPBERRY- pi3 controller is used as processing hardware. All sensors and actuation devices are interfaced with this controller. It has also been provided to log data. The software will be developed in python /C language. The software has the following modules.
a)	Water pump controller to collect water to sink the vessel. 
b)	A solenoid valve to release water and to move up.
c)	Control algorithm to maintain the trajectory of the vessel at the pre-calculated spot.
d)	Actuation of propelling motors to provide thrust in forwarding direction.
e)	Operation of a small pump to collect water samples. 
f)	Initialize all measurement sensors. Collect data from sensors and process them.
g)	Store data in a zip drive. Such that it can be recovered easily at the shore. 
h)	Open solenoid valve of required chamber of sample collection to store samples to be collected at shore for detailed investigation. 
i)	Collect data from GPS as marking point. 
j)	Transmit data through the LoRA modules. 
k)	Transfer all data through communication link at shore.\
5.6 GPS and Communication module 
GPS  and communication antenna is placed on top of the bot. A Patch antenna for GPS and a whip antenna for LoRA communication is planned. The Lora module is connected to RPi through SPI link. 
6.	Application : There are numerous application for this task. They are given below.
a)	Survey of water bed from river, lakes or pond for the primary investigation of water quality. This may be suitable for the clean Ganga project. 
b)	Survey of water to alert danger situation for fishes.
c)	  Survey of Sea and Ocean to reach benefit to the fisherman to locate a correct fishing spot
d)	Finding and rescue tasks underwater during disasters such as floods and Tsunamis.
7.	Further work

The idea is formulated by a group of students which are further discussed and deliberated by the concerned faculties. The work will find a boost in case of acceptance of the internal project. The task is unique and will open up many directions in the future. There are many DST, AICTE, UGC sponsored projects related to water management. Since the topic is new in concept, there can be the generation of papers and patents.
8.	Cost of the Project – 452,000




 Quick process of what is done. 

The robot dives into the water taking in various readings such as dissolved oxygen, pH, and barometric pressure. It processes that information and gives a probability of where the maximum number of fish could be found. So initially we choose a starting and that’s all you need to do. The rest is handled by the vehicle. It dives 5 meters into the water body and travels in straight lines to form a rectangle. It stops at, every corner of the rectangle to collect water samples and pictures of the area  and analyze values. Once it collects the sample it turns and moves towards the next vertex. It does this ‘N’ times, thereby completing a rectangle. It analyzes the values to form a probability distribution which it displays to the user understandably. This helps the authorities Know the location of people or things that are trapped underwater and they are identified and rescued.
 
![image](https://github.com/user-attachments/assets/a5d6652d-13cb-4f51-a9e4-f640e5139af0)


References : 
1.	https://www.aquasure.com.au/seawater-quality-monitoring
2.	https://archive.epa.gov/water/archive/web/html/vms50.html
3.	A Fish Farmer's Guide to Understanding Water Quality - Part 1 | The F... https://thefishsite.com/articles/a-fish-farmers-guide-to-understanding-...
4.	Guobao Xu 1, Yanjun Shi 2, Xueyan Sun 3 and Weiming Shen 3,*” Internet of Things in Marine Environment Monitoring: A Review”, Sensors 2019, 19, 1711
5.	Gauging the Ganga- Guidelines for sampling and monitoring water quality.
6.	Xianyu Zhang 1,2, Yingqi Zhang 1,2, Qian Zhang 1,2,*, Peiwu Liu 1, Rui Guo 1,2, Shengyi Jin 1, Jiawen Liu 1, Lei Chen 1, Zhen Ma 1,2 and Ying Liu, “Evaluation and Analysis of Water Quality of Marine Aquaculture Area”, Int. J. Environ. Res. Public Health 2020, 17, 1446; doi:10.3390/ijerph17041446




Dashboard Design


<img width="1256" alt="image" src="https://github.com/user-attachments/assets/c1e9c122-0dda-4360-aada-b02ae4275821" />


<img width="1264" alt="image" src="https://github.com/user-attachments/assets/88eeccd9-0426-4ac8-9e25-0442b56b6c55" />


<img width="1264" alt="image" src="https://github.com/user-attachments/assets/8d260d40-80f1-45d9-b4c8-c4d252371a76" />



<img width="1268" alt="image" src="https://github.com/user-attachments/assets/17b0acb3-72ba-497b-b6a0-5df437c87b93" />


<img width="1268" alt="image" src="https://github.com/user-attachments/assets/fdadd4cf-8f31-4d6f-aecc-d281b23a55da" />



