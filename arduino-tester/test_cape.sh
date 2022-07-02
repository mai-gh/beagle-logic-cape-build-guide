while true; do
  clear
  sigrok-cli -d beaglelogic:logic_channels=14 -c samplerate=100M --samples=64
  sleep .2s
done
