void align_with_silo2()
{
  imus();
  cor = (w + x + z) / 3;
  if (sensor[proxi_wall] == 1)
  {
    ms = 140;
    imus();
    backward(yawDeg,imutune);
  }
  else if (silo_count == 1)
  {
    ms = 140;
    lsa_backward_with_imu();
    delay(130);
    halt();
    delay(150);
    cor = (w + x + z) / 3;
    silo_check2();
  }

  else if (silo_count == 2)
  {
    ms = 140;
    lsa_backward_with_imu();
    delay(150);
    halt();
    delay(150);
    cor = (w + x + z) / 3;
    silo_check2();
  }

  else
  {
    ms = 140;
    lsa_backward_with_imu();
    delay(700);
    halt();
    delay(150);
    cor = (w + x + z) / 3;
    silo_check2();
  }

}


void silo_check2()
{
  
  //--------------aligning with the lines of the silo-------------//
  if ((sensor[proxi_silo_left] == 1 || sensor[proxi_silo_right] == 1) && silo_count <= 1 && (sensor[frontlsa] < 10 || sensor[frontlsa] > 60))
  {
     while(sensor[frontlsa] < 20 || sensor[frontlsa] > 50)
     {
      imus();
      ms=90;
      left(yawDeg,imutune);
     }
    halt();
    imus();
    delay(40);
  }

  //---------------first silo filling--------------//
  else if ((sensor[proxi_silo_left] == 1 && sensor[proxi_silo_right] == 1) && silo_count == 1 && (sensor[frontlsa] >= 20 && sensor[frontlsa] <= 50))
  {
    free_fall(255);
    delay(1800);
    imus();
    free_fall(0);
    retry=1;
    corner =200;
    imu_balance();
    x = -480;
    y = -480;
    z = -480;
    w = -480;
    cor = (w + x + z) / 3;
    temp = 0;
    ballpick=1;
    leftwall2 = silobuffforleft - 30;
    i3silo2 = silobufffori3 + 150;
    i2silo2 = silobufffori2 - 80;
//    reset_imu();
    i = 1;
  }

  //-----------------different silo filling-------------//
  else if ((sensor[proxi_silo_left] == 1 && sensor[proxi_silo_right] == 1) && (silo_count > 1 || silo_count < 5) && (sensor[frontlsa] >= 20 || sensor[frontlsa] <= 50))
  {
    free_fall(255);
    delay(1800);
    free_fall(0);
    imus();
    retry=1;
    corner=200;
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    cor = (w + x + z) / 3;
    temp = 0;
    i = 5;
  }

  //--------------------checking for different silo if 1st silo is filled-------------//
  else if ((sensor[proxi_silo_left] == 0 || sensor[proxi_silo_right] == 0))
  {
    silo_flag = 1;
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    while (silo_flag == 1)
    {
      ms = 90;
      imus();
      
   //----------------silo checking on left side-----------//
      if (silo_count < 4)
      {
        if ((x + y) / 2 < 100)
        {
          left(yawDeg, imutune);
        }
        else if (sensor[frontlsa] < 30 || sensor[frontlsa] > 40)
        {
          ms = 90;
          left(yawDeg, imutune);
        }
        else
        {
          halt();
          imus();
          delay(40);
          silo_flag = 0;
          x = 0;
          y = 0;
          z = 0;
          w = 0;
          silo_count++;
        }
      }

   //------------if all silo's are filled on the left side-------------//
      else if (silo_count == 4)
      {

        if ((w + z) / 2 < 800)
        {
          ms = 110;
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
          imus();
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

void back_to_position2()
{
  //  imus();
  ms = 100;
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
    while ((w + z) / 2 < 500 || sensor[frontlsa] < 20 || sensor[frontlsa] > 50)
    {
      imus();
      right(yawDeg, imutune);
    }
    i = 1;
  }
  else if (silo_count == 5)
  {
    while ((x + y) / 2 < 100 || sensor[frontlsa] < 20 || sensor[frontlsa] > 50)
    {
      imus();
      left(yawDeg, imutune);
    }
    i = 1;
  }
  halt();
  imu_balance();
   x = -480;
    y = -480;
    z = -480;
    w = -480;
    
  silo_count = 1;
  cor = (w + x + z) / 3;
//  reset_imu();
  delay(100);
  //  align=1;
}
