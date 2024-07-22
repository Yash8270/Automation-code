void imus()
{

  // if(!myIMU.begin())
  // {
  //  digitalWrite(ledred,HIGH);
  // }

  // else
  // {
  //  digitalWrite(ledred, LOW);
  // imu::Vector<3> acc = myIMU.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  //  imu::Vector<3> gyro = myIMU.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
  //  imu::Vector<3> mag = myIMU.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);
  imu::Quaternion quat = myIMU.getQuat();

  yy = quat.y() * quat.y(); // 2 Uses below

  // roll = atan2(2 * (quat.w() * quat.x() + quat.y() * quat.z()), 1 - 2*(quat.x() * quat.x() + yy));
  // pitch = asin(2 * quat.w() * quat.y() - quat.x() * quat.z());
  yaw = atan2(2 * (quat.w() * quat.z() + quat.x() * quat.y()), 1 - 2 * (yy + quat.z() * quat.z()));

  /*  Convert Radians to Degrees */
  // rollDeg  = 57.2958 * roll;
  // pitchDeg = 57.2958 * pitch;
  yawDeg   = 57.2958 * yaw;
  //  Serial.println(yawDeg);
  //  Serial.println();
  // }
}

void imu_clock_right(float angle)
{
  //  imus();
  if(ballpick>0 && sensor[id]==1) angle=angle-6;
  while (yawDeg > angle)
  {
    //    Serial.println("Rotate 90 clock");

    imus();
    clockwise();
  }
  halt();
}

void imu_clock_line()
{
  //  imus();
  while (yawDeg > -174)
  {
    //    Serial.println("Rotate 180 clock");
    imus();
    clockwise();
  }
  halt();
}

void reset_imu()
{
  //  digitalWrite(imupin, LOW);
//  delay(650);
  //  digitalWrite(imupin, HIGH);
  myIMU.begin();
}

void imu_anticlock()
{
  //  imus();
  while (yawDeg < 83)
  {
    //    Serial.println("Rotate Anti-clock");
    imus();
    anti_clock();
  }
  halt();
}

void imu_balance()
{
  imus();
  velocity=40;
  if(yawDeg < -2)
  {
    while(yawDeg < -2)
    {
      imus();
      anti_clock();
    }
  }
  else if(yawDeg > 0)
  {
    while(yawDeg > 0)
    {
      imus();
      clockwise();
    }
  }
  velocity=140;
}

void imu_anticlock_line()
{
  //  imus();
  while (yawDeg < 174)
  {
    //    Serial.println("Rotate 180 clock");
    imus();
    anti_clock();
  }
  halt();
}
