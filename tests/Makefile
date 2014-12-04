OBJS:=sat.tex

sat.pdf: ${OBJS}

%.dvi: ${OBJS}
	latex ${OBJS}

%.ps: %.dvi
	dvips $<

%.pdf: %.ps
	ps2pdf $<

.PHONY: clean
clean:
	[ -f projectplan.toc ] && rm projectplan.toc || true
	[ -f projectplan.dvi ] && rm projectplan.dvi || true
	[ -f projectplan.pdf ] && rm projectplan.pdf || true
