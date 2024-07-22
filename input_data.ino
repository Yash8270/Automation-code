void sensordata(int howMany)
{
  
  if (howMany == sizeof(sensor))
  {
    Wire.readBytes((char*)sensor, sizeof(sensor));
  }

}

//void manipulation()
//{
//  if(signx==1)
// {
//  x=fakex + 256*nx;
// }
// else
// {
//  if(modx==0)
//  {
//    x=fakex - 256*nx;
//  }
//  else
//  {
//    x=fakex - 256*(nx+1);
//  }
// }
//
// if(signy==1)
// {
//  y=fakey + 256*ny;
// }
// else
// {
//  if(mody==0)
//  {
//    y=fakey - 256*ny;
//  }
//  else
//  {
//    y=fakey - 256*(ny+1);
//  }
// }
//}

void printing()
{
  for (int i = 0; i < 9; i++)
  {
    Serial.println(sensor[i]);
  }
  Serial.println("");
}
