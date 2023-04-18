void reconnect()
{
  while(!mqttClient.connected())
  {
    Serial.println("Attempting MQTT Connection..");
    mqttClient.connect("Siva");
  }
  Serial.println("Connected");
}


void publishStatus(String id,bool value){
  Jsondata="";
  data.clear();
  data["event"]="status";
  data["value"]=value;
  serializeJson(data, Jsondata);
  mqttClient.publish(id.c_str(),Jsondata.c_str()); 
}

void publishData(struct deviceInfo device){
  Jsondata="";
  data.clear();
  data["event"]="data";
  data["voltage"]=device.voltage;
  data["current"]=device.current;
  data["power"]=device.power;
  serializeJson(data,Jsondata);
  mqttClient.publish(device.id.c_str(),Jsondata.c_str()); 
}