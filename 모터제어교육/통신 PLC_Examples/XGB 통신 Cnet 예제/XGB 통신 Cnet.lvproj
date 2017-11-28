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
		<Item Name="SubVI" Type="Folder">
			<Item Name="Serial Delay(msec).vi" Type="VI" URL="../Serial Delay(msec).vi"/>
			<Item Name="응답 프레임.vi" Type="VI" URL="../응답 프레임.vi"/>
		</Item>
		<Item Name="XGB" Type="Folder">
			<Item Name="XGB 쓰기.vi" Type="VI" URL="../XGB/XGB 쓰기.vi"/>
			<Item Name="XGB 읽기.vi" Type="VI" URL="../XGB/XGB 읽기.vi"/>
			<Item Name="연속 읽기 응답 Parsing.vi" Type="VI" URL="../XGB/연속 읽기 응답 Parsing.vi"/>
		</Item>
		<Item Name="XGT" Type="Folder">
			<Item Name="Time Bar.vi" Type="VI" URL="../XGT/Time Bar.vi"/>
			<Item Name="XGT 개별쓰기 Enquire.vi" Type="VI" URL="../XGT/XGT 개별쓰기 Enquire.vi"/>
			<Item Name="XGT 개별쓰기 응답프레임.vi" Type="VI" URL="../XGT/XGT 개별쓰기 응답프레임.vi"/>
			<Item Name="XGT 개별읽기 Enquire.vi" Type="VI" URL="../XGT/XGT 개별읽기 Enquire.vi"/>
			<Item Name="XGT 개별읽기 응답프레임.vi" Type="VI" URL="../XGT/XGT 개별읽기 응답프레임.vi"/>
			<Item Name="XGT 결과 읽기.vi" Type="VI" URL="../XGT/XGT 결과 읽기.vi"/>
			<Item Name="XGT 연속쓰기 Enquire.vi" Type="VI" URL="../XGT/XGT 연속쓰기 Enquire.vi"/>
			<Item Name="XGT 연속쓰기 응답프레임.vi" Type="VI" URL="../XGT/XGT 연속쓰기 응답프레임.vi"/>
			<Item Name="XGT 연속읽기 (독립).vi" Type="VI" URL="../XGT/XGT 연속읽기 (독립).vi"/>
			<Item Name="XGT 연속읽기 (독립)01.vi" Type="VI" URL="../XGT/XGT 연속읽기 (독립)01.vi"/>
			<Item Name="XGT 연속읽기 (독립)ONOFF.vi" Type="VI" URL="../XGT/XGT 연속읽기 (독립)ONOFF.vi"/>
			<Item Name="XGT 연속읽기 Enquire.vi" Type="VI" URL="../XGT/XGT 연속읽기 Enquire.vi"/>
			<Item Name="XGT 연속읽기 응답 문자열 처리.vi" Type="VI" URL="../XGT/XGT 연속읽기 응답 문자열 처리.vi"/>
			<Item Name="XGT 연속읽기.vi" Type="VI" URL="../XGT/XGT 연속읽기.vi"/>
			<Item Name="XGT 읽기(수정).vi" Type="VI" URL="../XGT/XGT 읽기(수정).vi"/>
			<Item Name="XGT 읽기.vi" Type="VI" URL="../XGT/XGT 읽기.vi"/>
			<Item Name="XGT 통신(SubVI).vi" Type="VI" URL="../XGT/XGT 통신(SubVI).vi"/>
			<Item Name="Zero oFF (SubVI).vi" Type="VI" URL="../XGT/Zero oFF (SubVI).vi"/>
		</Item>
		<Item Name="BCC.vi" Type="VI" URL="../BCC.vi"/>
		<Item Name="XGB 개별 쓰기.vi" Type="VI" URL="../XGB/XGB 개별 쓰기.vi"/>
		<Item Name="XGB 개별 읽기.vi" Type="VI" URL="../XGB/XGB 개별 읽기.vi"/>
		<Item Name="XGB 연속 쓰기(BCC).vi" Type="VI" URL="../XGB/XGB 연속 쓰기(BCC).vi"/>
		<Item Name="XGB 연속 쓰기.vi" Type="VI" URL="../XGB/XGB 연속 쓰기.vi"/>
		<Item Name="XGB 연속 읽기.vi" Type="VI" URL="../XGB/XGB 연속 읽기.vi"/>
		<Item Name="응답 Parsing.vi" Type="VI" URL="../XGB/응답 Parsing.vi"/>
		<Item Name="의존성" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="BuildHelpPath.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/BuildHelpPath.vi"/>
				<Item Name="Check Special Tags.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Check Special Tags.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Convert property node font to graphics font.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Convert property node font to graphics font.vi"/>
				<Item Name="Details Display Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Details Display Dialog.vi"/>
				<Item Name="DialogType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogType.ctl"/>
				<Item Name="DialogTypeEnum.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogTypeEnum.ctl"/>
				<Item Name="Error Code Database.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Code Database.vi"/>
				<Item Name="ErrWarn.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/ErrWarn.ctl"/>
				<Item Name="eventvkey.ctl" Type="VI" URL="/&lt;vilib&gt;/event_ctls.llb/eventvkey.ctl"/>
				<Item Name="Find Tag.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Find Tag.vi"/>
				<Item Name="Format Message String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Format Message String.vi"/>
				<Item Name="General Error Handler Core CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler Core CORE.vi"/>
				<Item Name="General Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler.vi"/>
				<Item Name="Get String Text Bounds.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Get String Text Bounds.vi"/>
				<Item Name="Get Text Rect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Get Text Rect.vi"/>
				<Item Name="GetHelpDir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetHelpDir.vi"/>
				<Item Name="GetRTHostConnectedProp.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetRTHostConnectedProp.vi"/>
				<Item Name="Longest Line Length in Pixels.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Longest Line Length in Pixels.vi"/>
				<Item Name="LVBoundsTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVBoundsTypeDef.ctl"/>
				<Item Name="LVRectTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVRectTypeDef.ctl"/>
				<Item Name="Not Found Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Not Found Dialog.vi"/>
				<Item Name="Search and Replace Pattern.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Search and Replace Pattern.vi"/>
				<Item Name="Set Bold Text.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set Bold Text.vi"/>
				<Item Name="Set String Value.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set String Value.vi"/>
				<Item Name="Simple Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Simple Error Handler.vi"/>
				<Item Name="TagReturnType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/TagReturnType.ctl"/>
				<Item Name="Three Button Dialog CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog CORE.vi"/>
				<Item Name="Three Button Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="VISA Configure Serial Port" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port"/>
				<Item Name="VISA Configure Serial Port (Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Instr).vi"/>
				<Item Name="VISA Configure Serial Port (Serial Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Serial Instr).vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
			</Item>
			<Item Name="10진수변환.vi" Type="VI" URL="../10진수변환.vi"/>
			<Item Name="Leak결과.vi" Type="VI" URL="../XGT/Leak결과.vi"/>
		</Item>
		<Item Name="빌드 스펙" Type="Build"/>
	</Item>
</Project>
