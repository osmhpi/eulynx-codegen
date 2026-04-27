all: EulynxBaseline4Release3.loc.csv EulynxBaseline4Release2.loc.csv EulynxBaseline4Release1.loc.csv

clean:
	rm *.loc.csv

%.loc.csv:
	printf "" > $@
	for f in $(wildcard ../$*/04_OutputC/*); do \
		printf $$f >> $@; \
		printf "," >> $@; \
		cloc --quiet --csv --include-lang="C" --sum-one $$f | tail -n 1 | cut -d, -f5 | tr -d $$'\n' >> $@; \
		printf "," >> $@; \
		cloc --quiet --csv --include-lang="C/C++ Header" --sum-one $$f | tail -n 1 | cut -d, -f5 | tr -d $$'\n' >> $@; \
		printf "," >> $@; \
		echo "" >> $@; \
	done

