TARGET:=final.pdf

OBJS:=final.tex changes.tex projectreflection.tex personalreflection.tex designs.tex

final.pdf: ${OBJS}

%.dvi: ${OBJS}
	latex ${OBJS}

%.ps: %.dvi
	dvips $<

%.pdf: %.ps
	ps2pdf $<

.PHONY: clean
clean:
	[ -f final.toc ] && rm final.toc || true
	[ -f final.dvi ] && rm final.dvi || true
	[ -f final.pdf ] && rm final.pdf || true
