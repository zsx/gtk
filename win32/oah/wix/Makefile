###################
# MACROs
#

!IFNDEF version
!  ERROR version macro not specified
!ENDIF

!IFNDEF api_ver
!  ERROR api_ver macro not specified
!ENDIF

!IFNDEF bin_ver
!  ERROR bin_ver macro not specified
!ENDIF

!IFNDEF release_path
release_path=..\Win32\Release
!  MESSAGE release_path not defined, but set to $(release_path)
!ENDIF

module=gtk

# output directories
output=.\Win32
IntDir=$(output)\obj
PDBDir=$(output)\pdb

# Tools
LIGHT=light.exe /nologo /o $(output)\$@ /pdbout $(PDBDir)\$*.wixpdb
TEMPLATE_TOOL=%OAH_INSTALLED_PATH%bin\wixt "$?" $(release_path) $(module)-$(api_ver)

###################
# makefile targets
#
full: create_intdir dev

clean:
  -rd /Q /S $(output) 2>nul

create_intdir:
  @if NOT exist $(IntDir)\nul mkdir $(IntDir) >nul

#
# WIMP
#
wimp: wimp.msm

wimp.msm: $(IntDir)\wimp.wixobj
  $(LIGHT) $?

$(IntDir)\wimp.wxs: wimp.wxs.in; sed.exe -e "s/@VERSION@/$(version)/g" -e "s/@API_VERSION@/$(api_ver)/g" -e "s/@BINARY_VERSION@/$(bin_ver)/g" "$?" > "$@"

#
# Redistributable Merge Modules containing binaries/shared [libraries/objects]
#
redist: $(module)-$(api_ver).msm

$(module)-$(api_ver).msm: $(IntDir)\$(module)-$(api_ver).wixobj
  $(LIGHT) $?

$(IntDir)\$(module)-$(api_ver).wxs: $(module)-$(api_ver).wxs.in; sed.exe -e "s/@VERSION@/$(version)/g" -e "s/@API_VERSION@/$(api_ver)/g" -e "s/@BINARY_VERSION@/$(bin_ver)/g" "$?" > "$@"

#
# -dev package 
#
dev: redist wimp $(module)-$(api_ver)-dev.msm $(module)-$(version)dev.msi

$(module)-$(api_ver)-dev.msm: $(IntDir)\$(module)-$(api_ver)-dev.wixobj
  $(LIGHT) $?

$(module)-$(version)dev.msi: $(IntDir)\$(module)-$(api_ver)-dev-installer.wixobj
  $(LIGHT) $?

$(IntDir)\$(module)-$(api_ver)-dev.wxs: $(IntDir)\$(module)-$(api_ver)-dev.wxs.template
  $(TEMPLATE_TOOL) > "$@"

$(IntDir)\$(module)-$(api_ver)-dev-installer.wxs: $(module)-$(api_ver)-dev-installer.wxs.in; sed.exe -e "s/@VERSION@/$(version)/g" -e "s/@API_VERSION@/$(api_ver)/g" -e "s/@BINARY_VERSION@/$(bin_ver)/g" "$?" > "$@"
$(IntDir)\$(module)-$(api_ver)-dev.wxs.template: $(module)-$(api_ver)-dev.wxs.template.in; sed.exe -e "s/@VERSION@/$(version)/g" -e "s/@API_VERSION@/$(api_ver)/g" -e "s/@BINARY_VERSION@/$(bin_ver)/g" "$?" > "$@"

###################
# makefile inference rules
#
.SUFFIXES: .wxs .wixobj

{$(IntDir)}.wxs{$(IntDir)}.wixobj::
  candle.exe /nologo /out $(IntDir)\ $<
