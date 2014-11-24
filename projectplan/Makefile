TARGET:=projectplan.pdf

all: projectplan.pdf

%.dvi: %.tex
	latex $<

%.pdf: %.dvi
	dvipdfm $<

.PHONY: clean
clean:
	[ -f projectplan.toc ] && rm projectplan.toc || true
	[ -f projectplan.pdf ] && rm projectplan.pdf || true
