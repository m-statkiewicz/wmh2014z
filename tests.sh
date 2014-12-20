echo "n;lambda;sigma;k;maxIter;eval;deltaTime"
for n in 4 8 32
do
	for l in 4 8 16
	do
		for s in 2 6
		do
			for k in 10 5 2
			do
				for i in 10 100 1000
				do
					for x in {1..20}
					do
						echo -n "$n;$l;$s;$k;$i;"
						./target/wmh.o -i $i -n $n -l $l -m $s -k $k
					done
				done
			done
		done
	done
done

