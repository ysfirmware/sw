<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="14008000">
	<Item Name="내 컴퓨터" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">내 컴퓨터/VI 서버</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">내 컴퓨터/VI 서버</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Dll 호출.vi" Type="VI" URL="../Dll 호출.vi"/>
		<Item Name="FileSave.vi" Type="VI" URL="../FileSave.vi"/>
		<Item Name="의존성" Type="Dependencies">
			<Item Name="LVSaveFile.dll" Type="Document" URL="../../builds/DLL 생성/나의 DLL/LVSaveFile.dll"/>
		</Item>
		<Item Name="빌드 스펙" Type="Build">
			<Item Name="나의 DLL" Type="DLL">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{B368036E-9C1A-4E5F-97E8-68E0DC2B6BEF}</Property>
				<Property Name="App_INI_GUID" Type="Str">{A27ED9DE-A961-4F39-89B9-F23851845C50}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.edu.com</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{44BAE75F-C6A3-49A9-A605-99C9A19B440B}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">나의 DLL</Property>
				<Property Name="Bld_defaultLanguage" Type="Str">Korean</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/나의 DLL</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{4418787E-E53C-40E6-86FB-F174917B7128}</Property>
				<Property Name="Bld_version.build" Type="Int">3</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">LVSaveFile.dll</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/나의 DLL/LVSaveFile.dll</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">지원 디렉토리</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/나의 DLL/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Dll_compatibilityWith2011" Type="Bool">false</Property>
				<Property Name="Dll_delayOSMsg" Type="Bool">true</Property>
				<Property Name="Dll_headerGUID" Type="Str">{141CCA24-E723-4DE8-ABEC-3C9A4CC7856C}</Property>
				<Property Name="Dll_libGUID" Type="Str">{FFE1C386-DEBF-4B92-AEEB-8BE731CCC7E4}</Property>
				<Property Name="Source[0].itemID" Type="Str">{A14181BE-A6FF-4079-A66A-EA8291D26912}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/내 컴퓨터/FileSave.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">ExportedVI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">edu</Property>
				<Property Name="TgtF_fileDescription" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_internalName" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">저작권 2015 edu</Property>
				<Property Name="TgtF_productName" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{ABCE6B72-FE00-4A4A-AAF4-BA3F1085C2C2}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">LVSaveFile.dll</Property>
			</Item>
		</Item>
	</Item>
</Project>
