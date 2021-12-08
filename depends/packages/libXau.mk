package=libXau
$(package)_version=1.0.8
$(package)_download_path=https://github.com/msy2008/Toolbox/releases/download/v1.0
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=fdd477320aeb5cdd67272838722d6b7d544887dfe7de46e1e7cc0c27c2bea4f2
$(package)_dependencies=xproto

define $(package)_set_vars
  $(package)_config_opts=--disable-shared
  $(package)_config_opts_linux=--with-pic
endef

define $(package)_config_cmds
  $($(package)_autoconf)
endef

define $(package)_build_cmds
  $(MAKE)
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install
endef
