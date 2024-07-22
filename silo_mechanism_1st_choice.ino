
//-----------silo function from center line---------//
void silo()
{
  if (i == 1)
  {
    //    Ycor=temp;
    x = temp - 150;
    y = temp - 150;
    z = temp - 150;
    w = temp - 150;
    cor = (w + x + z) / 3;
    while (cor > i1silo)
    {
      //      Serial.println("i=============1");
      imus();
      cor = (w + x + z) / 3;
//      line_position();
      //      if (sensor[frontlsa] > 70 || cor > 400)
      //      {
      backward(yawDeg, imutune);
      //      }
      //      else
      //      {
      //        lsa_backward();
      //      }
    }
    i = 10;
  }
  else if (i == 2)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor > i2silo)
    {
      //      Serial.println("i=============2 AND back");
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    imu_anticlock();
    reset_imu();
    x = Ycor;
    y = Ycor;
    w = Ycor;
    z = Ycor;
    cor = (w + x + z) / 3;
    while (cor > 5)
    {
      //      Serial.println("i============2 AND silo");
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }
  else if ((i == 3 || i == 6) && cor < i3silo)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor < i3silo)
    {
      //      Serial.println("i==============3 AND back<795");
      imus();
      cor = (w + x + z) / 3;
      forward(yawDeg, imutune);
    }
    if (i == 3)
    {
      imu_clock_right(-78);
    }
    else
    {
      imu_anticlock();
    }
    reset_imu();
    x = Ycor;
    y = Ycor;
    z = Ycor;
    w = Ycor;
    cor = (w + x + z) / 3;
    while (cor > 5)
    {
      //      Serial.println("i==================2 AND silo<795");
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }
  else if ((i == 3 || i == 6) && cor > i3silo)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor > i3silo)
    {
      //      Serial.println("i============3 AND back>795");
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    if (i == 3)
    {
      imu_clock_right(-78);
    }
    else
    {
      imu_anticlock();
    }
    reset_imu();
    x = Ycor;
    y = Ycor;
    z = Ycor;
    w = Ycor;
    cor = (w + x + z) / 3;
    while (cor > 5)
    {
      //      Serial.println("i=============3 AND silo>795");
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }
}

void picking(int d)
{
  digitalWrite(pickmd, LOW);
  analogWrite(pickpwm, d);
}

void free_fall(int d)
{
  digitalWrite(fallmd, LOW);
  analogWrite(fallpwm, d);
}

void purple(int id)
{
  if (id == 1)
  {
    picking(0);
    free_fall(0);
    silo();
  }
  else if (id == 2)
  {
    picking(255);
    free_fall(255);
    delay(1500);
    forward(0, 1);
  }
  else
  {
    picking(255);
    free_fall(0);
  }
}

void left_shift(int state)
{
  //  imus();
//  cor = (abs(w) + abs(x) + abs(y) + abs(z)) / 4;
    cor = (abs(w) + abs(x) + abs(z))/3;
  while (cor < 100)
  {
    imus();
//    cor = (abs(w) + abs(x) + abs(y) + abs(z)) / 4;
    cor = (abs(w) + abs(x) + abs(z))/3;
    left(yawDeg, imutune);
  }
  if (state != 6)
  {
    Ycor = Ycor - cor;
    i = 6;
  }
  else
  {
    Ycor = Ycor + cor;
    i = 3;
  }
  imu_anticlock_line();
  reset_imu();
  x = 0;
  y = 0;
  z = 0;
  w = 0;
  cor = (w + x + z) / 3;
  temp = 0;
  corner3=530;
//  i7silo2 = 250;
  retry=0;
}

void right_shift(int state)
{
  //  imus();
//  cor = (abs(w) + abs(x) + abs(y) + abs(z)) / 4;
    cor = (abs(w) + abs(x) + abs(z))/3;
  while (cor < 300)
  {
    imus();
//    cor = (abs(w) + abs(x) + abs(y) + abs(z)) / 4;
    cor = (abs(w) + abs(x) + abs(z))/3;
    right(yawDeg, imutune);
  }
  if (state != 6)
  {
    Ycor = Ycor - cor;
    i = 6;
  }
  else
  {
    Ycor = Ycor + cor;
    i = 3;
  }
  imu_clock_line();
  reset_imu();
  x = 0;
  y = 0;
  z = 0;
  w = 0;
  cor = (w + x + z) / 3;
  temp = 0;
  corner=480;
//  i7silo2 = 250;
  retry=0;
}
