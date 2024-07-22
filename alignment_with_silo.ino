
void align_with_silo()
{
  //  line_position();
  cor = (w + x + z) / 3;
  if (sensor[proxi_wall] == 1)
  {
    ms = 140;
    lsa_backward_with_imu();
    //    line_position();
  }
  else if (silo_count == 1)
  {
    ms = 140;
    //    line_position();
    lsa_backward_with_imu();
    delay(100);
    //    reset_imu();
    halt();
    delay(150);
    //    line_position();
    cor = (w + x + z) / 3;
    silo_check();
  }

  else if (silo_count == 2)
  {
    ms = 140;
    lsa_backward_with_imu();
    delay(150);
    //    reset_imu();
    halt();
    delay(150);
    cor = (w + x + z) / 3;
    silo_check();
  }

  else
  {
    ms = 140;
    lsa_backward_with_imu();
    delay(700);
    //    reset_imu();
    halt();
    delay(150);
    cor = (w + x + z) / 3;
    silo_check();
  }


}

void silo_check()
{
  if ((sensor[proxi_silo_left] == 1 || sensor[proxi_silo_right] == 1) && silo_count <= 1 && (sensor[frontlsa] < 15 || sensor[frontlsa] > 55))
  {
    if ((w + z) / 2 < cor)
    {
      while (sensor[frontlsa] < 20 || sensor[frontlsa] > 50)
      {
        imus();
        ms = 90;
        right(yawDeg, imutune);
      }
    }
    else if ((w + z) / 2 > cor)
    {
      while (sensor[frontlsa] < 20 || sensor[frontlsa] > 50)
      {
        imus();
        ms = 90;
        left(yawDeg, imutune);
      }
    }
    halt();
    delay(40);
  }

  else if ((sensor[proxi_silo_left] == 1 || sensor[proxi_silo_right] == 1) && silo_count == 1 && (sensor[frontlsa] >= 20 && sensor[frontlsa] <= 50))
  {
    free_fall(255);
    delay(2000);
    free_fall(0);
    x = -200;
    y = -200;
    z = -200;
    w = -200;
    cor = (w + x + z) / 3;
    temp = 0;
    i = 1;
    //    align = 1;
  }
  else if ((sensor[proxi_silo_left] == 1 || sensor[proxi_silo_right] == 1) && (silo_count > 1 || silo_count < 5) && (sensor[frontlsa] >= 20 || sensor[frontlsa] <= 50))
  {
    free_fall(255);
    delay(2000);
    free_fall(0);
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    cor = (w + x + z) / 3;
    temp = 0;
    i = 5;
    //    align = 1;
  }

  else if ((sensor[proxi_silo_left] == 0 && sensor[proxi_silo_right] == 0))
  {
    silo_flag = 1;
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    //    i=5;
    while (silo_flag == 1)
    {
      ms = 140;
      imus();
      if (silo_count < 3)
      {
        if ((x + y) / 2 < 100)
        {
          left(yawDeg, imutune);
        }
        else if (sensor[frontlsa] < 30 || sensor[frontlsa] > 40)
        {
          ms = 100;
          left(yawDeg, imutune);
        }
        else
        {
          halt();
          delay(40);
          silo_flag = 0;
          x = 0;
          y = 0;
          z = 0;
          w = 0;
          //          align = 0;
          silo_count++;
        }
      }
      else if (silo_count >= 3 && silo_count < 5)
      {
        if ((w + z) / 2 < 100 && silo_count == 4)
        {
          right(yawDeg, imutune);
        }
        else if ((w + z) / 2 < 500 && silo_count == 3)
        {
          right(yawDeg, imutune);
        }
        else if (sensor[frontlsa] < 20 || sensor[frontlsa] > 50)
        {
          ms = 90;
          right(yawDeg, imutune);
        }
        else
        {
          halt();
          delay(40);
          silo_flag = 0;
          x = 0;
          y = 0;
          z = 0;
          w = 0;
          //          align = 0;
          silo_count++;
        }
      }
      else
      {
        silo_flag = 0;
        //        align = 0;
        halt();
        i = 4;
      }
    }
  }
  cor = (w + x + z) / 3;
}

void back_to_position()
{
  //  imus();
  ms = 120;
  if (silo_count == 2)
  {
    while ((w + z) / 2 < 100 || sensor[frontlsa] < 20 || sensor[frontlsa] > 50)
    {
      imus();
      right(yawDeg, imutune);
    }
    i = 1;
  }
  else if (silo_count == 3)
  {
    while ((w + z) / 2 < 300 || sensor[frontlsa] < 20 || sensor[frontlsa] > 50)
    {
      imus();
      right(yawDeg, imutune);
    }
    i = 1;
  }
  else if (silo_count == 4)
  {
    while ((x + y) / 2 < 100 || sensor[frontlsa] < 20 || sensor[frontlsa] > 50)
    {
      imus();
      left(yawDeg, imutune);
    }
    i = 1;
  }
  else if (silo_count == 5)
  {
    while ((x + y) / 2 < 300 || sensor[frontlsa] < 20 || sensor[frontlsa] > 50)
    {
      imus();
      left(yawDeg, imutune);
    }
    i = 1;
  }
  halt();
  x = -200;
  y = -200;
  z = -200;
  w = -200;
  silo_count = 1;
  cor = (w + x + z) / 3;
  delay(100);
  //  align=1;
}
