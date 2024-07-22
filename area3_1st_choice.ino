void area3_navigation()
{
  //-----------------------------ball checking-------------------------------//
  if (sensor[id] == 2 && i != 5 && i != 10)
  {
    delay(80);
    halt();
    picking(0);
    free_fall(255);
    delay(1200);

  }
  else if (sensor[id] == 1 && i != 5 && i != 10)
  {
    halt();
    delay(300);
    picking(0);
    free_fall(0);
    ms = 220;
    silo();
  }
  else if (i != 5 && i != 10)
  {
    picking(255);
    free_fall(0);
  }

  //------------------------Navigation------------------------------//
  if (cor > frontwall && i == 1)
  {
    Ycor = temp - 100;
    imu_clock_right(-83);
    reset_imu();
    //        halt();
    //        delay(100);
    cor = 0;                       
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    temp = 0;
    i = 2;
  }
  else if (cor > rightwall && i == 2)
  {
    imu_clock_line();
    reset_imu();                        
    cor = 0;
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    temp = 0;
    i = 3;
  }
  else if (cor > leftwall && i == 3)
  {
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    cor = (w + x + z) / 3;
    left_shift(i);
  }
  else if (i == 4)
  {
    halt();
  }
  else if (i == 5)
  {
    back_to_position();
  }
  else if (i == 10)
  {
    align_with_silo();
  }
  else if (cor > leftwall && i == 6)
  {
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    cor = (w + x + z) / 3;
    left_shift(i);
  }
  else
  {
    ms = 160;
    imus();
    cor = (w + x + z) / 3;
    temp = cor;                       
    forward(yawDeg, imutune);
  }
}
