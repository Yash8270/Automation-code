void lsa_forward()
{
  lsa_err = lsat - sensor[frontlsa];
  lsa_errd = (lsa_err - lsa_eprev);
  lsa_erri = lsa_erri + lsa_err;
  p = (lkp * lsa_err) + (lkd * lsa_errd) + (lki * lsa_erri);
  lsa_eprev = lsa_err;

  if (p > 30)
  {
    p = 30;
  }
  forward(p, 1);
}

void lsa_right()
{
  lsa_err = lsat - sensor[2];

  lsa_errd = (lsa_err - lsa_eprev);
  lsa_erri = lsa_erri + lsa_err;
  p = (lkp * lsa_err) + (lkd * lsa_errd) + (lki * lsa_erri);
  lsa_eprev = lsa_err;

  if (p > 30)
  {
    p = 30;
  }

  right(p, 1);

}

void lsa_left ()
{
  lsa_err = lsat - sensor[frontlsa];

  lsa_errd = (lsa_err - lsa_eprev);
  lsa_erri = lsa_erri + lsa_err;
  p = (lkp * lsa_err) + (lkd * lsa_errd) + (lki * lsa_erri);
  lsa_eprev = lsa_err;

  if (p > 30)
  {
    p = 30;
  }
  left(p, 1);
}

void lsa_backward()
{
  lsa_err = lsat - sensor[frontlsa];
  lsa_errd = (lsa_err - lsa_eprev);
  lsa_erri = lsa_erri + lsa_err;
  p = (lkp * lsa_err) + (lkd * lsa_errd) + (lki * lsa_erri);
  lsa_eprev = lsa_err;

  if (p > 30)
  {
    p = 30;
  }
  backward(p, 1);
}

void lsa_backward_with_imu()
{
  float alpha = 0;
  if (sensor[frontlsa] < 70)
  {
    lsa_err = lsat - sensor[frontlsa];
    lsa_errd = (lsa_err - lsa_eprev);
    lsa_erri = lsa_erri + lsa_err;
    alpha = (lkp * lsa_err) + (lkd * lsa_errd) + (lki * lsa_erri);
    lsa_eprev = lsa_err;
    if(alpha > 30)
    {
      alpha=30;
    }
    backward(alpha,1);
  }
  else
  {
    imus();
    backward(yawDeg, imutune);
  }
 
}


void lsa_forward_with_imu()
{
  float alpha=0;
  imus();
  if(sensor[frontlsa]<=70)
  {
   lsa_err = lsat - sensor[frontlsa];
   lsa_errd = (lsa_err - lsa_eprev);
   lsa_erri = lsa_erri + lsa_err;
   alpha = (lkp * lsa_err) + (lkd * lsa_errd) + (lki * lsa_erri);
   lsa_eprev = lsa_err;
  }
  if (alpha > 30)
  {
    alpha = 30;
  }
  forward_combine(alpha,imutune,yawDeg);
}

void line_follow_path()
{
  Serial.print("");
}
