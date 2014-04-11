# Simple Makefile to generate pdf from tex file specified in SRC using latex

# Note: Opens PDF in acrobat reader (acroread). Please substitute with preferred reader at line:32

# FLow: .tex--latex-->.dvi, .dvi--dvips-->.ps, .ps--ps2pdf-->.pdf

# Program requirements
# 1) latex
# 2) dvips
# 3) ps2pdf

# @author Barath Ramesh <ramesh@hcs.ufl.edu>

LATEX = latex
DVIPS = dvips
PS2PDF = ps2pdf

OUT_DIR = ./OUT
#SRC = c6000_architecture.tex
TEMP = ./temp/

DVI = $(patsubst %.tex,	 %.dvi, $(SRC))
PS	= $(patsubst %.dvi,	 %.ps,	$(DVI))
PDF = $(patsubst %.ps,	 $(OUT_DIR)%.pdf, $(PS))
AUX = $(patsubst %.tex,	 $(TEMP)%.aux, $(SRC))
LOG = $(patsubst %.tex,	 $(TEMP)%.log, $(SRC))
TOC = $(patsubst %.tex,	 $(TEMP)%.toc, $(SRC))
OUT = $(patsubst %.tex,	 $(TEMP)%.out, $(SRC))

.PHONY: clean 

all: $(PDF)
	@acroread $(PDF)

clean:
	@rm -f $(DVI)
	@rm -f $(PS)
	@rm -f $(PDF) 

#$(PDF):$(PS) $(DVI)

%.dvi: %.tex
	@$(LATEX) $(SRC)

%.ps: %.dvi
	@$(DVIPS) $< -o $@

$(OUT_DIR)%.pdf: %.ps
	@$(PS2PDF) $< $@

