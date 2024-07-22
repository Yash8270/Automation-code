void imu_path_area1_to_3()
{
//  cor = (abs(w) + abs(x) + abs(y) + abs(z)) / 4;
    cor = (abs(w) + abs(x) + abs(z))/3;
  imus();

  //------------------Start Zone/Retry Zone to water zone----------------//
  if (cor < first_step && sensor[proxi_zone] == 1 && lsa_flag == 0)
  {
    if (cor < (first_step - 200) && first_step > 1000)
    {
      if (cor < 200)
      {
        ms = 200;
      }
      else
      {
        ms = 230;
      }

    }
    else
    {
      ms = 160;
    }
    forward(yawDeg, imutune);
  }

  else if ((cor > first_step || sensor[proxi_zone] == 0) && lsa_flag == 0)
  {
    halt();
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    lsa_flag = 1;
    ms = 230;
  }

    //---------------------water zone to ramp----------------//
  else if (lsa_flag == 1 && (cor < 1260 || sensor[proxi_zone] == 0))
  {
    if (cor < 900)
    {
      ms = 230;
    }
    else
    {
      ms = 160;
    }
    left(yawDeg, imutune);
  }
  else if (lsa_flag == 1 && (cor > 1260 && sensor[proxi_zone] == 1))
  {
    halt();
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    lsa_flag = 2;
    ms = 220;
  }

 //---------------------Entering A3----------------//
  else if (lsa_flag == 2 && cor < third_step)
  {
    ms = 220;
    if (cor > 10 && cor < 540)
    {
      buff = 5;
    }
    else
    {
      buff = 0;
    }
    forward(yawDeg, imutune);
  }

  else if (lsa_flag == 2 && cor > third_step)
  {
    lsa_flag = 3;
  }

   //-----------------Rotation----------------//
  else if (lsa_flag == 3)
  {
    imu_clock_right(-83);
    reset_imu();
    halt();
    delay(50);
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    cor = (w+x+z)/3;
    i = 1;
  }


}
