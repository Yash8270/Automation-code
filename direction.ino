
void forward(float p, float imutune)
{
  float rightmotors = ms - imutune * p;
  float leftmotors = ms + imutune * p + buff;
  if (leftmotors > 255)
  {
    leftmotors = 230;
  }
  if (rightmotors > 255)
  {
    rightmotors = 230;
  }

  digitalWrite(md1, fl);
  analogWrite(pwm1, (int)(leftmotors));

  digitalWrite(md2, fr);
  analogWrite(pwm2, (int)(rightmotors));

  digitalWrite(md3, bl);
  analogWrite(pwm3, (int)(leftmotors));

  digitalWrite(md4, br);
  analogWrite(pwm4, (int)(rightmotors));
}

void backward(float p, float imutune)
{
  float leftmotors = ms - imutune * p;
  float rightmotors = ms + imutune * p;
  if (leftmotors > 255)
  {
    leftmotors = 230;
  }
  if (rightmotors > 255)
  {
    rightmotors = 230;
  }

  digitalWrite(md1, !fl);
  analogWrite(pwm1, (int)(leftmotors));

  digitalWrite(md2, !fr);
  analogWrite(pwm2, (int)(rightmotors));

  digitalWrite(md3, !bl);
  analogWrite(pwm3, (int)(leftmotors));

  digitalWrite(md4, !br);
  analogWrite(pwm4, (int)(rightmotors));

}

void left(float p, float imutune)
{
  float leftmotors = ms - imutune * p;
  float rightmotors = ms + imutune * p;
  if (leftmotors > 255)
  {
    leftmotors = 230;
  }
  if (rightmotors > 255)
  {
    rightmotors = 230;
  }

  digitalWrite(md1, !fl);
  analogWrite(pwm1, (int)(leftmotors));

  digitalWrite(md2, fr);
  analogWrite(pwm2, (int)(leftmotors));

  digitalWrite(md3, bl);
  analogWrite(pwm3, (int)(rightmotors));

  digitalWrite(md4, !br);
  analogWrite(pwm4, (int)(rightmotors));
}

void right(float p, float imutune)
{
  digitalWrite(md1, fl);
  analogWrite(pwm1, (int)(ms + imutune * p));

  digitalWrite(md2, !fr);
  analogWrite(pwm2, (int)(ms + imutune * p));

  digitalWrite(md3, !bl);
  analogWrite(pwm3, (int)(ms - imutune * p));

  digitalWrite(md4, br);
  analogWrite(pwm4, (int)(ms - imutune * p));
}

void anti_clock()
{
  digitalWrite(md1, !fl);
  analogWrite(pwm1, velocity);

  digitalWrite(md2, fr);
  analogWrite(pwm2, velocity);

  digitalWrite(md3, !bl);
  analogWrite(pwm3, velocity);

  digitalWrite(md4, br);
  analogWrite(pwm4, velocity);
}

void clockwise()
{
  digitalWrite(md1, fl);
  analogWrite(pwm1, velocity);

  digitalWrite(md2, !fr);
  analogWrite(pwm2, velocity);

  digitalWrite(md3, bl);
  analogWrite(pwm3, velocity);

  digitalWrite(md4, !br);
  analogWrite(pwm4, velocity);
}

void halt()
{
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
  analogWrite(pwm3, 0);
  analogWrite(pwm4, 0);
}

void left_slow()
{
  digitalWrite(md1, !fl);
  analogWrite(pwm1, slow_speed);

  digitalWrite(md2, fr);
  analogWrite(pwm2, slow_speed);

  digitalWrite(md3, bl);
  analogWrite(pwm3, slow_speed);

  digitalWrite(md4, !br);
  analogWrite(pwm4, slow_speed);
}

void forward_slow()
{
  digitalWrite(md1, fl);
  analogWrite(pwm1, slow_speed);

  digitalWrite(md2, fr);
  analogWrite(pwm2, slow_speed);

  digitalWrite(md3, bl);
  analogWrite(pwm3, slow_speed);

  digitalWrite(md4, br);
  analogWrite(pwm4, slow_speed);
}

void backward_combine(float p, float imutune, float yaw)
{
  digitalWrite(md1, !fl);
  analogWrite(pwm1, (int)(ms - p - imutune * yaw));

  digitalWrite(md2, !fr);
  analogWrite(pwm2, (int)(ms + p + imutune * yaw));

  digitalWrite(md3, !bl);
  analogWrite(pwm3, (int)(ms - p - imutune * yaw));

  digitalWrite(md4, !br);
  analogWrite(pwm4, (int)(ms + p + imutune * yaw));
}

void forward_combine(float p, float imutune, float yaw)
{
  digitalWrite(md1, fl);
  analogWrite(pwm1, (int)(ms - p - imutune * yaw));

  digitalWrite(md2, fr);
  analogWrite(pwm2, (int)(ms + p + imutune * yaw));

  digitalWrite(md3, bl);
  analogWrite(pwm3, (int)(ms - p - imutune * yaw));

  digitalWrite(md4, br);
  analogWrite(pwm4, (int)(ms + p + imutune * yaw));
}
