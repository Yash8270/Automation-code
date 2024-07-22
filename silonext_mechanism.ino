
//---------------silo function for line after center plus----------//
void silonext()
{
  
  //--------------ball found on frontwall-------------//
  if (i == 1)
  {
    ms=200;
    x = temp - 200;
    y = temp - 200;
    z = temp - 200;
    w = temp - 200;
    cor = (w + x + z) / 3;
    while ( cor > i1silo3)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

  //----------------------ball found on initial right----------------//
  else if (i == 2)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor > i2silo3)
    {
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
    ms=200;
    while ( cor > i1silo3)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

  //----------------------ball found on initial left before certain count----------------// 
  else if (i == 3 && cor < i3silo3)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor < i3silo3)
    {
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
    ms=200;
    while (cor > 5)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

  //----------------------ball found on initial left before certain count----------------// 
  else if (i == 3 && cor > i3silo3)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor > i3silo3)
    {
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
    w = Ycor;
    z = Ycor;
    cor = (w + x + z) / 3;
    ms=200;
    while (cor > 5)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

  //----------------------ball found on second right before certain count----------------//
  else if (i == 6 && cor < i6silo3)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor < i6silo3)
    {
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
    ms=200;
    while (cor > 10)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

   //----------------------ball found on second right after certain count----------------//
  else if (i == 6 && cor > i6silo3)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor > i6silo3)
    {
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
    ms=200;
    while (cor > 5)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

  //---------------ball found on the right corner--------------//
  else if (i == 7)
  {
    cor = (w + x + z) / 3;
    while (cor > i7silo3)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    imu_anticlock();
    reset_imu();
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    cor = (w + x + z) / 3;
    while (cor < i3silo3)
    {
      imus();
      cor = (w + x + z) / 3;
      forward(yawDeg, imutune);
    }
   imu_clock_right(-78);
    reset_imu();
    x = Ycor;
    y = Ycor;
    z = Ycor;
    w = Ycor;
    cor = (w + x + z) / 3;
    ms=200;
    while (cor > 5)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

//  //---------------ball found on the right corner--------------//
//  else if (i == 7 && cor < i7silo3)
//  {
//    cor = (w + x + z) / 3;
//    while (cor < i7silo3)
//    {
//      imus();
//      cor = (w + x + z) / 3;
//      bac(yawDeg, imutune);
//    }
//    imu_anticlock();
//    reset_imu();
//    x = 0;
//    y = 0;
//    z = 0;
//    w = 0;
//    cor = (w + x + z) / 3;
//    while (cor < i3silo3)
//    {
//      imus();
//      cor = (w + x + z) / 3;
//      forward(yawDeg, imutune);
//    }
//    imu_clock_right(-78);
//    reset_imu();
//    x = Ycor;
//    y = Ycor;
//    z = Ycor;
//    w = Ycor;
//    cor = (w + x + z) / 3;
//    ms=200;
//    while (cor > 5)
//    {
//      imus();
//      cor = (w + x + z) / 3;
//      backward(yawDeg, imutune);
//    }
//    i = 10;
//  }
}
