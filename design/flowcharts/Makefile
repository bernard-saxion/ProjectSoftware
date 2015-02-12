CONVERT:=umlet
CONVERTFLAGS:=-action=convert
UXFHEADFILE:=uml/uxf_head.xml
UXFFOOTFILE:=uml/uxf_foot.xml

%.png: %.uxf
	$(CONVERT) $(CONVERTFLAGS) -format=png -filename=$< -output=$@

%.svg: %.uxf
	$(CONVERT) $(CONVERTFLAGS) -format=svg -filename=$< -output=$@

