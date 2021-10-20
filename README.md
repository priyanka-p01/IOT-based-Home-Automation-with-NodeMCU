# IOT-based-Home-Automation-with-NodeMCU
Now get your alerts &amp; updates about home, wherever you are, with an SMS on your mobile! All with a simple NodeMCU project!<br>

<h3>Things used in this project</h3>
<ul> <em> Hardware Components </em>
  <li> NodeMCU ESP8266 Wifi Module </li>
  <li> Buzzer </li>
  <li>LED's </li>
  <li>Resistors</li>
  <li>Jumper Cables</li>
  <li>Breadboard</li>
  <li>DHT11 Humidity and Temperature sensor</li>
  <li>MQ-2 smoke sensor</li>
  <li>PIR Motion Sensor (generic)</li>
</ul>

<ul> <em> Software components </em> 
  <li> Blynk App for alerts on user's mobile </li>
  <li> Fritzing for circuit simulation </li>
  <li> Arduino IDE </li>
</ul>

<p>
  We know about fire accidents due to gas leakages in residential and commercial places due to various reasons, and then if there is any ignition then the gas rapidly catches fire. In vehicles which use CNG, if there is any leakage then there is also same possibility of the vehicle catching fire. Thus, we have developed a simple fire alarm circuit which provides you with alerts about your home/office/vehicle about fire, smoke or burglar intrusions.
The sensor in the circuit will sense the gas/smoke leakage, if the leakage is of high intensity it will alarm the buzzer so the owners will be alert to take precaution measures to minimize the possibility of fire accidents or any loss to life or property. A fire or alarm system is often monitored regionally within the premises, or remotely at an overseas place as per demand.

Remote alarm provides the owner of the premise with the advantage of observation from distant location associated taking immediate actions once an emergency message is received, unlike a manual system. With the advancement of human civilization, fire- safety has been a major concern. Fire hazards will be fatal and calumnious for industrial and unit security, conjointly alarming for human life. So, there comes the need of standalone autonomous and mobile fireplace detection systems. These systems render the works of fast detection, alarm notification, and generally initiation of fireside termination.
</p>

<p>
  Procedure to build the mechanism.

We used the following sensors and components:

1. Humidity and Temperature Sensor

2. Gas Detection (also used as Alcohol Detection) sensor

3. PIR Motion Sensor

4. Buzzer

5. NodeMCU

In this circuit, if the smoke detector catches any traces of any smoke, alcohol or gas, then it will alert the user through the Blynk mobile app via IoT cloud. Similarly is in the case of any unwanted movements

Here, we can read temperature and humidity data from DHT11 sensor and upload it to a Thing Speak cloud using Arduino Uno and ESP8266-01 module. Arduino Uno is MCU, it fetches a data of humidity and temperature from DHT11 sensor and Process it and give it to a ESP8266 Module. ESP8266 is a WIFI module, it is one of the leading platforms for Internet of Things. It can transfer a data to IOT cloud.

</p>

<h3>Circuit diagram </h3>
![image](https://user-images.githubusercontent.com/78416066/138027328-c4cc1d10-5a6e-4c2c-baa4-2d28e8c2fc48.png)

Project link on Hackster = https://www.hackster.io/smashers/iot-based-home-automation-with-nodemcu-4c3415
Project link on YouTube = https://youtu.be/asFa12EX1KE

