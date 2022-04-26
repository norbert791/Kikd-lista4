i=0

while [ $i -lt 4 ]
do
	./main testy4/example$i.tga > results/example$i.txt
	((i++))
done
