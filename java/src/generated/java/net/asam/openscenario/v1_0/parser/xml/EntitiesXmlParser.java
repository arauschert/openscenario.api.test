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
import net.asam.openscenario.v1_0.api.IEntitySelection;
import net.asam.openscenario.v1_0.api.IScenarioObject;
import net.asam.openscenario.v1_0.common.OscConstants;
import net.asam.openscenario.v1_0.impl.EntitiesImpl;
import net.asam.openscenario.v1_0.impl.EntitySelectionImpl;
import net.asam.openscenario.v1_0.impl.ScenarioObjectImpl;

/**
 * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
 * Filling a EntitiesImpl instance from an xml tree.
 *
 * @author RA Consulting OpenSCENARIO generation facility
 */
public class EntitiesXmlParser extends XmlComplexTypeParser<EntitiesImpl> {

  /**
   * Constructor
   *
   * @param messageLogger to log messages during parsing
   * @param filename to locate the messages in a file
   */
  public EntitiesXmlParser(IParserMessageLogger messageLogger, String filename) {
    super(messageLogger, filename);
    subElementParser = new SubElementParser(messageLogger, filename);
  }

  @Override
  public void parseElement(
      IndexedElement indexedElement, ParserContext parserContext, EntitiesImpl object) {
    messageLogger.logMessage(
        new FileContentMessage(
            "Start Parsing Entities",
            ErrorLevel.DEBUG,
            new Textmarker(
                indexedElement.getStartElementLocation().getLine(),
                indexedElement.getStartElementLocation().getColumn(),
                filename)));
    super.parseElement(indexedElement, parserContext, object);
    messageLogger.logMessage(
        new FileContentMessage(
            "End Parsing Entities",
            ErrorLevel.DEBUG,
            new Textmarker(
                indexedElement.getEndElementLocation().getLine(),
                indexedElement.getEndElementLocation().getColumn(),
                filename)));
  }

  @Override
  protected Map<String, IAttributeParser<EntitiesImpl>> getAttributeNameToAttributeParserMap() {
    Map<String, IAttributeParser<EntitiesImpl>> result =
        new Hashtable<String, IAttributeParser<EntitiesImpl>>();
    return result;
  }

  /** Parser for all subelements */
  private class SubElementParser extends XmlSequenceParser<EntitiesImpl> {
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
    protected List<IElementParser<EntitiesImpl>> createParserList() {
      List<IElementParser<EntitiesImpl>> result = new ArrayList<IElementParser<EntitiesImpl>>();
      result.add(new SubElementScenarioObjectsParser());
      result.add(new SubElementEntitySelectionsParser());
      return result;
    }
  }
  /** A parser for subelement scenarioObjects */
  private class SubElementScenarioObjectsParser implements IElementParser<EntitiesImpl> {

    /** Constructor */
    public SubElementScenarioObjectsParser() {
      super();
      scenarioObjectXmlParser = new ScenarioObjectXmlParser(messageLogger, filename);
    }

    private ScenarioObjectXmlParser scenarioObjectXmlParser;

    @Override
    public void parse(
        IndexedElement indexedElement, ParserContext parserContext, EntitiesImpl object) {
      ScenarioObjectImpl scenarioObjects = new ScenarioObjectImpl();
      // Setting the parent
      scenarioObjects.setParent(object);
      scenarioObjectXmlParser.parseElement(indexedElement, parserContext, scenarioObjects);
      List<IScenarioObject> scenarioObjectsList = object.getScenarioObjects();
      if (scenarioObjectsList == null) {
        scenarioObjectsList = new ArrayList<IScenarioObject>();
        object.setScenarioObjects(scenarioObjectsList);
      }
      scenarioObjectsList.add(scenarioObjects);
    }

    @Override
    public int getMinOccur() {
      return 0;
    }

    @Override
    public int getMaxOccur() {
      return -1;
    }

    @Override
    public boolean doesMatch(String elementName) {
      return elementName.equals(OscConstants.ELEMENT__SCENARIO_OBJECT);
    }

    @Override
    public String[] getExpectedTagNames() {
      return new String[] {OscConstants.ELEMENT__SCENARIO_OBJECT};
    }
  }
  /** A parser for subelement entitySelections */
  private class SubElementEntitySelectionsParser implements IElementParser<EntitiesImpl> {

    /** Constructor */
    public SubElementEntitySelectionsParser() {
      super();
      entitySelectionXmlParser = new EntitySelectionXmlParser(messageLogger, filename);
    }

    private EntitySelectionXmlParser entitySelectionXmlParser;

    @Override
    public void parse(
        IndexedElement indexedElement, ParserContext parserContext, EntitiesImpl object) {
      EntitySelectionImpl entitySelections = new EntitySelectionImpl();
      // Setting the parent
      entitySelections.setParent(object);
      entitySelectionXmlParser.parseElement(indexedElement, parserContext, entitySelections);
      List<IEntitySelection> entitySelectionsList = object.getEntitySelections();
      if (entitySelectionsList == null) {
        entitySelectionsList = new ArrayList<IEntitySelection>();
        object.setEntitySelections(entitySelectionsList);
      }
      entitySelectionsList.add(entitySelections);
    }

    @Override
    public int getMinOccur() {
      return 0;
    }

    @Override
    public int getMaxOccur() {
      return -1;
    }

    @Override
    public boolean doesMatch(String elementName) {
      return elementName.equals(OscConstants.ELEMENT__ENTITY_SELECTION);
    }

    @Override
    public String[] getExpectedTagNames() {
      return new String[] {OscConstants.ELEMENT__ENTITY_SELECTION};
    }
  }
}
