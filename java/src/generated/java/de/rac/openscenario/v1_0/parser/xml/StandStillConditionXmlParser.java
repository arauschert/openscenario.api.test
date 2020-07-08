/*
 * Copyright 2020 RA Consulting
 *
 * RA Consulting GmbH licenses this file under the Apache License, 
 * Version 2.0 (the "License"); you may not use this file except 
 * in compliance with the License. 
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package de.rac.openscenario.v1_0.parser.xml;

import de.rac.openscenario.common.IParserMessageLogger;
import de.rac.openscenario.v1_0.common.OscConstants;
import de.rac.openscenario.simple.struct.IndexedElement;
import de.rac.openscenario.parser.ParserContext;
import de.rac.openscenario.v1_0.parser.CatalogReferenceParserContext;
import de.rac.openscenario.common.FileContentMessage;
import de.rac.xml.indexer.Position;
import de.rac.openscenario.common.Textmarker;
import de.rac.openscenario.common.ErrorLevel;
import java.util.List;

import de.rac.openscenario.v1_0.impl.StandStillConditionImpl;

import de.rac.openscenario.parser.modelgroup.XmlSequenceParser;
import java.util.Map;
import java.util.Hashtable;
import java.util.ArrayList;
import de.rac.openscenario.parser.type.XmlComplexTypeParser;


/**
 * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
 * Filling a StandStillConditionImpl instance from an xml tree.
 * 
 * @author RA Consulting OpenSCENARIO generation facility
*/
public class StandStillConditionXmlParser extends XmlComplexTypeParser<StandStillConditionImpl> {

	/**
	 * Constructor
	 * @param messageLogger to log messages during parsing
	 * @param filename to locate the messages in a file
	 */
	public StandStillConditionXmlParser(IParserMessageLogger messageLogger, String filename) {
		super(messageLogger, filename);
		subElementParser = new SubElementParser(messageLogger, filename);
	}
	@Override
	public void parseElement(IndexedElement indexedElement, ParserContext parserContext,StandStillConditionImpl object) {
		messageLogger.logMessage(new FileContentMessage("Start Parsing StandStillCondition", ErrorLevel.DEBUG, new Textmarker(indexedElement.getStartElementLocation().getLine(), indexedElement.getStartElementLocation().getColumn(), filename))); 
		super.parseElement(indexedElement,  parserContext, object);
		messageLogger.logMessage(new FileContentMessage("End Parsing StandStillCondition", ErrorLevel.DEBUG, new Textmarker(indexedElement.getEndElementLocation().getLine(), indexedElement.getEndElementLocation().getColumn(), filename))); 
	
	}			
	
	@Override
	protected  Map<String, IAttributeParser<StandStillConditionImpl>> getAttributeNameToAttributeParserMap()
	{
		Map<String, IAttributeParser<StandStillConditionImpl>> result  = new Hashtable<String, IAttributeParser<StandStillConditionImpl>>();
		result.put(OscConstants.ATTRIBUTE__DURATION, new IAttributeParser<StandStillConditionImpl>() {
			@Override
			public void parse(Position startPosition, Position endPosition, String attributeName, String attributeValue, StandStillConditionImpl object)
			{
				
				Textmarker startMarker = new Textmarker(startPosition.getLine(), startPosition.getColumn(),filename);
				Textmarker endMarker = new Textmarker(endPosition.getLine(), endPosition.getColumn(),filename);
				if (isParametrized(attributeValue))
				{
					object.setAttributeParameter(OscConstants.ATTRIBUTE__DURATION, stripDollarSign(attributeValue), startMarker); 
				}else
				{
					// Parse value
					// Simple type
					object.setDuration(parseDouble(attributeValue,startMarker));
				}
				object.putPropertyStartMarker(OscConstants.ATTRIBUTE__DURATION, startMarker);
				object.putPropertyEndMarker(OscConstants.ATTRIBUTE__DURATION, endMarker);
				
			}
			

			@Override
			public int getMinOccur() {
				return 1;
			}
			
		});
		return result;
	}

	/**
	 * Parser for all subelements
	 */
	private class SubElementParser extends XmlSequenceParser<StandStillConditionImpl>{
		/**
		 * Constructor
		 * @param messageLogger to log messages during parsing
		 * @param filename to locate the messages in a file
		 */
		public SubElementParser (IParserMessageLogger messageLogger, String filename) {
			super( messageLogger, filename);	
		}
		/*
		 * Creates a list of parser
		 */
		protected  List<IElementParser<StandStillConditionImpl>> createParserList()
		{
			List<IElementParser<StandStillConditionImpl>> result = new ArrayList<IElementParser<StandStillConditionImpl>>();
			return result;
		
		}	
	}
}

