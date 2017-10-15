#!/bin/sh

if [ $# -lt 1 ]; then
  echo "Usage: $0 <version>  1>&2"
  exit 1
fi


VERSION=$1
GOOGLE=/opt/android-sdk/extras/google/m2repository/com/google
AAR2JAR=/usr/local/bin/aar2jar.sh

#rm *.jar

$AAR2JAR $GOOGLE/android/gms/play-services-ads/$VERSION/play-services-ads-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-ads-light/$VERSION/play-services-ads-light-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-base/$VERSION/play-services-base-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-basement/$VERSION/play-services-basement-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-gass/$VERSION/play-services-gass-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-clearcut/$VERSION/play-services-clearcut-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-safetynet/$VERSION/play-services-safetynet-$VERSION.aar lib/



 ls -l lib/*.jar
 
