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
package net.asam.openscenario.v1_0.parser.xml;

import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;
import net.asam.openscenario.common.ErrorLevel;
import net.asam.openscenario.common.FileContentMessage;
import net.asam.openscenario.common.IParserMessageLogger;
import net.asam.openscenario.common.Textmarker;
import net.asam.openscenario.parser.ParserContext;
import net.asam.openscenario.parser.modelgroup.XmlSequenceParser;
import net.asam.openscenario.parser.type.XmlComplexTypeParser;
import net.asam.openscenario.simple.struct.IndexedElement;
import net.asam.openscenario.v1_0.common.OscConstants;
import net.asam.openscenario.v1_0.impl.OverrideSteeringWheelActionImpl;
import net.asam.xml.indexer.Position;

/**
 * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
 * Filling a OverrideSteeringWheelActionImpl instance from an xml tree.
 *
 * @author RA Consulting OpenSCENARIO generation facility
 */
public class OverrideSteeringWheelActionXmlParser
    extends XmlComplexTypeParser<OverrideSteeringWheelActionImpl> {

  /**
   * Constructor
   *
   * @param messageLogger to log messages during parsing
   * @param filename to locate the messages in a file
   */
  public OverrideSteeringWheelActionXmlParser(IParserMessageLogger messageLogger, String filename) {
    super(messageLogger, filename);
    subElementParser = new SubElementParser(messageLogger, filename);
  }

  @Override
  public void parseElement(
      IndexedElement indexedElement,
      ParserContext parserContext,
      OverrideSteeringWheelActionImpl object) {
    messageLogger.logMessage(
        new FileContentMessage(
            "Start Parsing OverrideSteeringWheelAction",
            ErrorLevel.DEBUG,
            new Textmarker(
                indexedElement.getStartElementLocation().getLine(),
                indexedElement.getStartElementLocation().getColumn(),
                filename)));
    super.parseElement(indexedElement, parserContext, object);
    messageLogger.logMessage(
        new FileContentMessage(
            "End Parsing OverrideSteeringWheelAction",
            ErrorLevel.DEBUG,
            new Textmarker(
                indexedElement.getEndElementLocation().getLine(),
                indexedElement.getEndElementLocation().getColumn(),
                filename)));
  }

  @Override
  protected Map<String, IAttributeParser<OverrideSteeringWheelActionImpl>>
      getAttributeNameToAttributeParserMap() {
    Map<String, IAttributeParser<OverrideSteeringWheelActionImpl>> result =
        new Hashtable<String, IAttributeParser<OverrideSteeringWheelActionImpl>>();
    result.put(
        OscConstants.ATTRIBUTE__VALUE,
        new IAttributeParser<OverrideSteeringWheelActionImpl>() {
          @Override
          public void parse(
              Position startPosition,
              Position endPosition,
              String attributeName,
              String attributeValue,
              OverrideSteeringWheelActionImpl object) {

            Textmarker startMarker =
                new Textmarker(startPosition.getLine(), startPosition.getColumn(), filename);
            Textmarker endMarker =
                new Textmarker(endPosition.getLine(), endPosition.getColumn(), filename);
            if (isParametrized(attributeValue)) {
              object.setAttributeParameter(
                  OscConstants.ATTRIBUTE__VALUE, stripDollarSign(attributeValue), startMarker);
            } else {
              // Parse value
              // Simple type
              object.setValue(parseDouble(attributeValue, startMarker));
            }
            object.putPropertyStartMarker(OscConstants.ATTRIBUTE__VALUE, startMarker);
            object.putPropertyEndMarker(OscConstants.ATTRIBUTE__VALUE, endMarker);
          }

          @Override
          public int getMinOccur() {
            return 1;
          }
        });
    result.put(
        OscConstants.ATTRIBUTE__ACTIVE,
        new IAttributeParser<OverrideSteeringWheelActionImpl>() {
          @Override
          public void parse(
              Position startPosition,
              Position endPosition,
              String attributeName,
              String attributeValue,
              OverrideSteeringWheelActionImpl object) {

            Textmarker startMarker =
                new Textmarker(startPosition.getLine(), startPosition.getColumn(), filename);
            Textmarker endMarker =
                new Textmarker(endPosition.getLine(), endPosition.getColumn(), filename);
            if (isParametrized(attributeValue)) {
              object.setAttributeParameter(
                  OscConstants.ATTRIBUTE__ACTIVE, stripDollarSign(attributeValue), startMarker);
            } else {
              // Parse value
              // Simple type
              object.setActive(parseBoolean(attributeValue, startMarker));
            }
            object.putPropertyStartMarker(OscConstants.ATTRIBUTE__ACTIVE, startMarker);
            object.putPropertyEndMarker(OscConstants.ATTRIBUTE__ACTIVE, endMarker);
          }

          @Override
          public int getMinOccur() {
            return 1;
          }
        });
    return result;
  }

  /** Parser for all subelements */
  private class SubElementParser extends XmlSequenceParser<OverrideSteeringWheelActionImpl> {
    /**
     * Constructor
     *
     * @param messageLogger to log messages during parsing
     * @param filename to locate the messages in a file
     */
    public SubElementParser(IParserMessageLogger messageLogger, String filename) {
      super(messageLogger, filename);
    }
    /*
     * Creates a list of parser
     */
    protected List<IElementParser<OverrideSteeringWheelActionImpl>> createParserList() {
      List<IElementParser<OverrideSteeringWheelActionImpl>> result =
          new ArrayList<IElementParser<OverrideSteeringWheelActionImpl>>();
      return result;
    }
  }
}
