let serialPDM;          // variable to hold an instance of the serialport library
let portName = 'COM3';  // fill in your serial port name here
let sensors;

function setup() {
  serialPDM = new PDMSerial(portName);
  
    // Alias for the sensor Data . You can also just use serialPDM.sensorData...
  sensors = serialPDM.sensorData;
  
  createCanvas(800,600);
}

function draw() {
  background(serialPDM.sensorData.a0,0,0);
  fill(255);
  console.log(serialPDM.sensorData.a0);
}

function mousePressed(){
  serialPDM.transmit('mouse', mouseX);
  console.log(mouseX);
}