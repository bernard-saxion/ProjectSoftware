TARGET:=projectplan.pdf

all: projectplan.pdf

%.dvi: %.tex
	latex $<

%.pdf: %.dvi
	dvipdfm $<
