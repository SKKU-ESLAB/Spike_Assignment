# See LICENSE for license details.

bbl_subproject_deps = \
	util \
  softfloat \
  machine \

bbl_hdrs = \
  bbl.h \

bbl_c_srcs = \
  logo.c \

bbl_asm_srcs = \
  raw_logo.S \

ifeq (dummy_payload,dummy_payload)
bbl_subproject_deps += \
  dummy_payload
endif

ifneq (dummy_payload,no)
bbl_asm_srcs += \
  payload.S

payload.o: bbl_payload

bbl_payload: $(BBL_PAYLOAD)
	if $(READELF) -h $< 2> /dev/null > /dev/null; then $(OBJCOPY) -O binary --set-section-flags .bss=alloc,load,contents $< $@; else cp $< $@; fi
endif

raw_logo.o: bbl_logo_file

ifeq (,1)
bbl_logo_file: riscv_logo.txt
	cat $^ | sed 's/$$/\r/' > $@
else
bbl_logo_file:
	touch $@
endif

bbl_test_srcs =

bbl_install_prog_srcs = \
  bbl.c \

bbl.bin: bbl
	$(OBJCOPY) -S -O binary --change-addresses -0x80000000 $< $@

bbl_extra_targets = bbl.bin
