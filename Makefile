all: cleaned.xmi cleaned_23.xmi

cleaned_19.xmi: EULYNX\ System\ BL4\ v19\ -\ BL4.xmi
		LC_ALL=C tr '\0-\10\13\14\16-\37' '[ *]' < "$<" > tmp.xmi
		# Truncate the profile garbage, skip all lines after the uml model
		sed -n '/<\/uml:Model>/q;p' tmp.xmi > $@
		# Close the XML tags
		echo "</uml:Model>" >> $@
		echo "</xmi:XMI>" >> $@
		rm tmp.xmi

cleaned_22.xmi: EULYNX\ System\ -\ BL\ 4\ V22.xmi
		LC_ALL=C tr '\0-\10\13\14\16-\37' '[ *]' < "$<" > tmp.xmi
		# Truncate the profile garbage, skip all lines after the uml model
		sed -n '/<\/uml:Model>/q;p' tmp.xmi > $@
		# Close the XML tags
		echo "</uml:Model>" >> $@
		echo "</xmi:XMI>" >> $@
		rm tmp.xmi

cleaned_23.xmi: EULYNX\ System\ BL4\ v23\ -\ BL4.xmi
		LC_ALL=C tr '\0-\10\13\14\16-\37' '[ *]' < "$<" > tmp.xmi
		# Truncate the profile garbage, skip all lines after the uml model
		sed -n '/<\/uml:Model>/q;p' tmp.xmi > $@
		# Close the XML tags
		echo "</uml:Model>" >> $@
		echo "</xmi:XMI>" >> $@
		rm tmp.xmi
