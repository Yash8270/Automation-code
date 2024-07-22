//void reset_encoder(int data,int s)
//{
//  Wire.beginTransmission(0x10);
//  encoder(data);
//  tempx=data;
////  tempy=data;
//  Wire.write(signd);
//  Wire.write(modd);
//  Wire.write(nd);
//  Wire.write(tempx);
////  Wire.write(tempy);
//  Wire.write(s);
//  Wire.endTransmission();
//
//}
//
//
//  void encoder(int data)
// {
//    nd=abs(data/256);
//   if(data>=0)
//   {
//    signd=1;
//   }
//   else
//   {
//    signd=0;
//    modd=abs(data%256);
//   }
// }

void ENCFR()
{
  if (digitalRead(frpin) == HIGH)
  {
    x = x + 1;
  }
  else
  {
    x = x - 1;
  }
}
void ENCFL()
{
  if (digitalRead(flpin) == HIGH)
  {
    w = w + 1;
  }
  else
  {
    w = w - 1;
  }
}

void ENCBL()
{
  if (digitalRead(blpin) == HIGH)
  {
    y = y + 1;
  }
  else
  {
    y = y - 1;
  }
}
void ENCBR()
{
  if (digitalRead(brpin) == HIGH)
  {
    z = z + 1;
  }
  else
  {
    z = z - 1;
  }
}
