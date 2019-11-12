mod_mod_rx.la: mod_mod_rx.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_mod_rx.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_mod_rx.la
