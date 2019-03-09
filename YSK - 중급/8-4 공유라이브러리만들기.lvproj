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
		<Item Name="ArrayFile.vi" Type="VI" URL="../ArrayFile.vi"/>
		<Item Name="DLL 호출.vi" Type="VI" URL="../DLL 호출.vi"/>
		<Item Name="의존성" Type="Dependencies">
			<Item Name="SharedLib.dll" Type="Document" URL="../build/공유라이브러리만들기/SharedLib.dll"/>
		</Item>
		<Item Name="빌드 스펙" Type="Build">
			<Item Name="나의 DLL" Type="DLL">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{3C90A152-5296-433D-B2BA-F1E8D72E1F7E}</Property>
				<Property Name="App_INI_GUID" Type="Str">{EDB6A855-9267-4527-B50A-5A9E221991EB}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.lvedu09.com</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{743A0FEF-3CF5-4A6C-9687-1FA60F7D9867}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">나의 DLL</Property>
				<Property Name="Bld_defaultLanguage" Type="Str">Korean</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../build/NI_AB_PROJECTNAME</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToProject</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{8C7EB173-5083-4C5B-BBE8-7AA6D6B422BB}</Property>
				<Property Name="Bld_version.build" Type="Int">2</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">SharedLib.dll</Property>
				<Property Name="Destination[0].path" Type="Path">../build/NI_AB_PROJECTNAME/SharedLib.dll</Property>
				<Property Name="Destination[0].path.type" Type="Str">relativeToProject</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">지원 디렉토리</Property>
				<Property Name="Destination[1].path" Type="Path">../build/NI_AB_PROJECTNAME/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">relativeToProject</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Dll_compatibilityWith2011" Type="Bool">false</Property>
				<Property Name="Dll_delayOSMsg" Type="Bool">true</Property>
				<Property Name="Dll_headerGUID" Type="Str">{BA735AC1-7907-4A9A-B427-DE3231AFC532}</Property>
				<Property Name="Dll_libGUID" Type="Str">{30CE9A77-BA27-476C-ACB5-8E7E9F38A1D3}</Property>
				<Property Name="Source[0].itemID" Type="Str">{9C365FB7-B9F8-4811-9874-C7CE65A0E51F}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/내 컴퓨터/ArrayFile.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">ExportedVI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">lvedu09</Property>
				<Property Name="TgtF_fileDescription" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_internalName" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">저작권 2019 lvedu09</Property>
				<Property Name="TgtF_productName" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{88B23817-C917-439C-8490-5C95A91F5FC7}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">SharedLib.dll</Property>
			</Item>
		</Item>
	</Item>
</Project>
