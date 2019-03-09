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
		<Item Name="Count UP.vi" Type="VI" URL="../Count UP.vi"/>
		<Item Name="Status.ctl" Type="VI" URL="../Status.ctl"/>
		<Item Name="콜라자판기(상태머신).vi" Type="VI" URL="../콜라자판기(상태머신).vi"/>
		<Item Name="콜라자판기(생산자소비자).vi" Type="VI" URL="../콜라자판기(생산자소비자).vi"/>
		<Item Name="의존성" Type="Dependencies"/>
		<Item Name="빌드 스펙" Type="Build">
			<Item Name="나의 어플리케이션" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{264F83B1-A789-4F49-8C79-89405A1E9EC1}</Property>
				<Property Name="App_INI_GUID" Type="Str">{CDF5006F-0719-446A-B7AF-F6924B184FFC}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{9814D78A-2FA1-41F5-A145-763BB6C7611B}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">나의 어플리케이션</Property>
				<Property Name="Bld_defaultLanguage" Type="Str">Korean</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/나의 어플리케이션</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{29EDEDED-FDAC-4800-9103-57C9A02D105F}</Property>
				<Property Name="Bld_version.build" Type="Int">1</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">콜라자판기.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/나의 어플리케이션/콜라자판기.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">지원 디렉토리</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/나의 어플리케이션/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{711BAC95-841E-47DC-B736-242B68939165}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/내 컴퓨터/콜라자판기(상태머신).vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_fileDescription" Type="Str">나의 어플리케이션</Property>
				<Property Name="TgtF_internalName" Type="Str">나의 어플리케이션</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">저작권 2015 </Property>
				<Property Name="TgtF_productName" Type="Str">나의 어플리케이션</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{C19D01CC-DF6B-4662-B4C6-7A0C638BF9B8}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">콜라자판기.exe</Property>
			</Item>
		</Item>
	</Item>
</Project>
