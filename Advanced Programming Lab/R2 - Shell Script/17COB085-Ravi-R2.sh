#!/bin/sh

a=0
n=7

while [ $a -le $n ]
do
   b=$a
   while [ $b -ge 0 ]
   do
      echo -n "$b "
      b=`expr $b - 1`
   done
   echo
   a=`expr $a + 1`
done

a=`expr $a - 2`
while [ $a -ge 0 ]
do
   b=$a
   while [ $b -ge 0 ]
   do
      echo -n "$b "
      b=`expr $b - 1`
   done
   echo
   a=`expr $a - 1`
done

