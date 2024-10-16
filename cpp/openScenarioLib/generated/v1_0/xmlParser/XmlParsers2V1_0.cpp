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
 
#include "XmlParsersV1_0.h"
#include "NamedReferenceProxy.h"
#include "FileContentMessage.h"
#include "Position.h"
#include "Textmarker.h"
#include "ErrorLevel.h"
#include "WrappedListParser.h"
#include "CatalogReferenceParserContextV1_0.h"

namespace NET_ASAM_OPENSCENARIO
{
    namespace v1_0
    {

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a EntityRefImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            EntityRefXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> EntityRefXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeEntityRef: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeEntityRef(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<EntityRefImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Proxy
                        auto proxy = std::make_shared<NamedReferenceProxy<IEntity>>(attributeValue);
                        proxy->SetParent(typedObject);
                        typedObject->SetEntityRef(proxy);
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, std::make_shared<AttributeEntityRef>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> EntityRefXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        EntityRefXmlParser::EntityRefXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a EntitySelectionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            EntitySelectionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> EntitySelectionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeName: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeName(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<EntitySelectionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__NAME, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetName(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<AttributeName>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> EntitySelectionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementMembersParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        EntitySelectionXmlParser::SubElementMembersParser::SubElementMembersParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _selectedEntitiesXmlParser = std::make_shared<SelectedEntitiesXmlParser>(messageLogger, filename, parserOptions);
        }

        void EntitySelectionXmlParser::SubElementMembersParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto members = std::make_shared<SelectedEntitiesImpl>();
            auto typedObject = std::static_pointer_cast<EntitySelectionImpl>(object);                    
            // Setting the parent
            members->SetParent(object);
            _selectedEntitiesXmlParser->ParseElement(indexedElement, parserContext, members);

            typedObject->SetMembers(members);
        }
        
        int EntitySelectionXmlParser::SubElementMembersParser::GetMinOccur() 
        {
            return 1;
        }

        int EntitySelectionXmlParser::SubElementMembersParser::GetMaxOccur() 
        {
            return 1;
        }

        bool EntitySelectionXmlParser::SubElementMembersParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__MEMBERS ;
        }

        std::vector<std::string> EntitySelectionXmlParser::SubElementMembersParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__MEMBERS
                    };
        }
  
        EntitySelectionXmlParser::EntitySelectionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a EnvironmentImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            EnvironmentXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> EnvironmentXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeName: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeName(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<EnvironmentImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__NAME, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetName(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<AttributeName>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> EnvironmentXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<WrappedListParser>(_messageLogger, _filename, std::make_shared<SubElementParameterDeclarationsParser>(_messageLogger, _filename, _parserOptions), OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATIONS, _parserOptions) );
            result.push_back(std::make_shared<SubElementTimeOfDayParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementWeatherParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementRoadConditionParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        EnvironmentXmlParser::SubElementParameterDeclarationsParser::SubElementParameterDeclarationsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _parameterDeclarationXmlParser = std::make_shared<ParameterDeclarationXmlParser>(messageLogger, filename, parserOptions);
        }

        void EnvironmentXmlParser::SubElementParameterDeclarationsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto parameterDeclarations = std::make_shared<ParameterDeclarationImpl>();
            auto typedObject = std::static_pointer_cast<EnvironmentImpl>(object);                    
            // Setting the parent
            parameterDeclarations->SetParent(object);
            _parameterDeclarationXmlParser->ParseElement(indexedElement, parserContext, parameterDeclarations);
            auto parameterDeclarationsList = typedObject->GetWriterParameterDeclarations();
            parameterDeclarationsList.push_back(parameterDeclarations);
            typedObject->SetParameterDeclarations(parameterDeclarationsList);
        }
        
        int EnvironmentXmlParser::SubElementParameterDeclarationsParser::GetMinOccur() 
        {
            return 0;
        }

        int EnvironmentXmlParser::SubElementParameterDeclarationsParser::GetMaxOccur() 
        {
            return -1;
        }

        bool EnvironmentXmlParser::SubElementParameterDeclarationsParser::DoesMatch(std::string& elementName)
        {
            return elementName == OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATION;
        }

        std::vector<std::string> EnvironmentXmlParser::SubElementParameterDeclarationsParser::GetExpectedTagNames()
        {
            return {OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATION};
        }
        EnvironmentXmlParser::SubElementTimeOfDayParser::SubElementTimeOfDayParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _timeOfDayXmlParser = std::make_shared<TimeOfDayXmlParser>(messageLogger, filename, parserOptions);
        }

        void EnvironmentXmlParser::SubElementTimeOfDayParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto timeOfDay = std::make_shared<TimeOfDayImpl>();
            auto typedObject = std::static_pointer_cast<EnvironmentImpl>(object);                    
            // Setting the parent
            timeOfDay->SetParent(object);
            _timeOfDayXmlParser->ParseElement(indexedElement, parserContext, timeOfDay);

            typedObject->SetTimeOfDay(timeOfDay);
        }
        
        int EnvironmentXmlParser::SubElementTimeOfDayParser::GetMinOccur() 
        {
            return 1;
        }

        int EnvironmentXmlParser::SubElementTimeOfDayParser::GetMaxOccur() 
        {
            return 1;
        }

        bool EnvironmentXmlParser::SubElementTimeOfDayParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__TIME_OF_DAY ;
        }

        std::vector<std::string> EnvironmentXmlParser::SubElementTimeOfDayParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__TIME_OF_DAY
                    };
        }
        EnvironmentXmlParser::SubElementWeatherParser::SubElementWeatherParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _weatherXmlParser = std::make_shared<WeatherXmlParser>(messageLogger, filename, parserOptions);
        }

        void EnvironmentXmlParser::SubElementWeatherParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto weather = std::make_shared<WeatherImpl>();
            auto typedObject = std::static_pointer_cast<EnvironmentImpl>(object);                    
            // Setting the parent
            weather->SetParent(object);
            _weatherXmlParser->ParseElement(indexedElement, parserContext, weather);

            typedObject->SetWeather(weather);
        }
        
        int EnvironmentXmlParser::SubElementWeatherParser::GetMinOccur() 
        {
            return 1;
        }

        int EnvironmentXmlParser::SubElementWeatherParser::GetMaxOccur() 
        {
            return 1;
        }

        bool EnvironmentXmlParser::SubElementWeatherParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__WEATHER ;
        }

        std::vector<std::string> EnvironmentXmlParser::SubElementWeatherParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__WEATHER
                    };
        }
        EnvironmentXmlParser::SubElementRoadConditionParser::SubElementRoadConditionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _roadConditionXmlParser = std::make_shared<RoadConditionXmlParser>(messageLogger, filename, parserOptions);
        }

        void EnvironmentXmlParser::SubElementRoadConditionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto roadCondition = std::make_shared<RoadConditionImpl>();
            auto typedObject = std::static_pointer_cast<EnvironmentImpl>(object);                    
            // Setting the parent
            roadCondition->SetParent(object);
            _roadConditionXmlParser->ParseElement(indexedElement, parserContext, roadCondition);

            typedObject->SetRoadCondition(roadCondition);
        }
        
        int EnvironmentXmlParser::SubElementRoadConditionParser::GetMinOccur() 
        {
            return 1;
        }

        int EnvironmentXmlParser::SubElementRoadConditionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool EnvironmentXmlParser::SubElementRoadConditionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ROAD_CONDITION ;
        }

        std::vector<std::string> EnvironmentXmlParser::SubElementRoadConditionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ROAD_CONDITION
                    };
        }
  
        EnvironmentXmlParser::EnvironmentXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a EnvironmentActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            EnvironmentActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> EnvironmentActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> EnvironmentActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementEnvironmentParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementCatalogReferenceParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        EnvironmentActionXmlParser::SubElementEnvironmentParser::SubElementEnvironmentParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _environmentXmlParser = std::make_shared<EnvironmentXmlParser>(messageLogger, filename, parserOptions);
        }

        void EnvironmentActionXmlParser::SubElementEnvironmentParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto environment = std::make_shared<EnvironmentImpl>();
            auto typedObject = std::static_pointer_cast<EnvironmentActionImpl>(object);                    
            // Setting the parent
            environment->SetParent(object);
            _environmentXmlParser->ParseElement(indexedElement, parserContext, environment);

            typedObject->SetEnvironment(environment);
        }
        
        int EnvironmentActionXmlParser::SubElementEnvironmentParser::GetMinOccur() 
        {
            return 0;
        }

        int EnvironmentActionXmlParser::SubElementEnvironmentParser::GetMaxOccur() 
        {
            return 1;
        }

        bool EnvironmentActionXmlParser::SubElementEnvironmentParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ENVIRONMENT ;
        }

        std::vector<std::string> EnvironmentActionXmlParser::SubElementEnvironmentParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ENVIRONMENT
                    };
        }
        EnvironmentActionXmlParser::SubElementCatalogReferenceParser::SubElementCatalogReferenceParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _catalogReferenceXmlParser = std::make_shared<CatalogReferenceXmlParser>(messageLogger, filename, parserOptions);
        }

        void EnvironmentActionXmlParser::SubElementCatalogReferenceParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto catalogReference = std::make_shared<CatalogReferenceImpl>();
            auto typedObject = std::static_pointer_cast<EnvironmentActionImpl>(object);                    
            // Setting the parent
            catalogReference->SetParent(object);
            _catalogReferenceXmlParser->ParseElement(indexedElement, parserContext, catalogReference);

            typedObject->SetCatalogReference(catalogReference);
            std::dynamic_pointer_cast<CatalogReferenceParserContext>(parserContext)->AddCatalogReference(std::dynamic_pointer_cast<ICatalogReference>(catalogReference));
        }
        
        int EnvironmentActionXmlParser::SubElementCatalogReferenceParser::GetMinOccur() 
        {
            return 0;
        }

        int EnvironmentActionXmlParser::SubElementCatalogReferenceParser::GetMaxOccur() 
        {
            return 1;
        }

        bool EnvironmentActionXmlParser::SubElementCatalogReferenceParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__CATALOG_REFERENCE ;
        }

        std::vector<std::string> EnvironmentActionXmlParser::SubElementCatalogReferenceParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__CATALOG_REFERENCE
                    };
        }
  
        EnvironmentActionXmlParser::EnvironmentActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a EnvironmentCatalogLocationImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            EnvironmentCatalogLocationXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> EnvironmentCatalogLocationXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> EnvironmentCatalogLocationXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementDirectoryParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        EnvironmentCatalogLocationXmlParser::SubElementDirectoryParser::SubElementDirectoryParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _directoryXmlParser = std::make_shared<DirectoryXmlParser>(messageLogger, filename, parserOptions);
        }

        void EnvironmentCatalogLocationXmlParser::SubElementDirectoryParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto directory = std::make_shared<DirectoryImpl>();
            auto typedObject = std::static_pointer_cast<EnvironmentCatalogLocationImpl>(object);                    
            // Setting the parent
            directory->SetParent(object);
            _directoryXmlParser->ParseElement(indexedElement, parserContext, directory);

            typedObject->SetDirectory(directory);
        }
        
        int EnvironmentCatalogLocationXmlParser::SubElementDirectoryParser::GetMinOccur() 
        {
            return 1;
        }

        int EnvironmentCatalogLocationXmlParser::SubElementDirectoryParser::GetMaxOccur() 
        {
            return 1;
        }

        bool EnvironmentCatalogLocationXmlParser::SubElementDirectoryParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__DIRECTORY ;
        }

        std::vector<std::string> EnvironmentCatalogLocationXmlParser::SubElementDirectoryParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__DIRECTORY
                    };
        }
  
        EnvironmentCatalogLocationXmlParser::EnvironmentCatalogLocationXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a EventImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            EventXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> EventXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeMaximumExecutionCount: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeMaximumExecutionCount(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<EventImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__MAXIMUM_EXECUTION_COUNT, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetMaximumExecutionCount(ParseUnsignedInt(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__MAXIMUM_EXECUTION_COUNT, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__MAXIMUM_EXECUTION_COUNT, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__MAXIMUM_EXECUTION_COUNT, std::make_shared<AttributeMaximumExecutionCount>(_messageLogger, _filename, _parserOptions)));
            class AttributeName: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeName(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<EventImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__NAME, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetName(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<AttributeName>(_messageLogger, _filename, _parserOptions)));
            class AttributePriority: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributePriority(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<EventImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__PRIORITY, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Enumeration Type
                        const auto kResult = Priority::GetFromLiteral(attributeValue);
                        if (kResult != Priority::UNKNOWN)
                        {
                            typedObject->SetPriority(attributeValue);
                        }
                        else
                        {
                            auto msg = FileContentMessage("Value '" + attributeValue + "' is not allowed.", ERROR, startMarker);
                            _messageLogger.LogMessage(msg);
                        }
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__PRIORITY, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__PRIORITY, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__PRIORITY, std::make_shared<AttributePriority>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> EventXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementActionsParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementStartTriggerParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        EventXmlParser::SubElementActionsParser::SubElementActionsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _actionXmlParser = std::make_shared<ActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void EventXmlParser::SubElementActionsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto actions = std::make_shared<ActionImpl>();
            auto typedObject = std::static_pointer_cast<EventImpl>(object);                    
            // Setting the parent
            actions->SetParent(object);
            _actionXmlParser->ParseElement(indexedElement, parserContext, actions);
            auto actionsList = typedObject->GetWriterActions();
            actionsList.push_back(actions);
            typedObject->SetActions(actionsList);
        }
        
        int EventXmlParser::SubElementActionsParser::GetMinOccur() 
        {
            return 1;
        }

        int EventXmlParser::SubElementActionsParser::GetMaxOccur() 
        {
            return -1;
        }

        bool EventXmlParser::SubElementActionsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ACTION ;
        }

        std::vector<std::string> EventXmlParser::SubElementActionsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ACTION
                    };
        }
        EventXmlParser::SubElementStartTriggerParser::SubElementStartTriggerParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _triggerXmlParser = std::make_shared<TriggerXmlParser>(messageLogger, filename, parserOptions);
        }

        void EventXmlParser::SubElementStartTriggerParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto startTrigger = std::make_shared<TriggerImpl>();
            auto typedObject = std::static_pointer_cast<EventImpl>(object);                    
            // Setting the parent
            startTrigger->SetParent(object);
            _triggerXmlParser->ParseElement(indexedElement, parserContext, startTrigger);

            typedObject->SetStartTrigger(startTrigger);
        }
        
        int EventXmlParser::SubElementStartTriggerParser::GetMinOccur() 
        {
            return 1;
        }

        int EventXmlParser::SubElementStartTriggerParser::GetMaxOccur() 
        {
            return 1;
        }

        bool EventXmlParser::SubElementStartTriggerParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__START_TRIGGER ;
        }

        std::vector<std::string> EventXmlParser::SubElementStartTriggerParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__START_TRIGGER
                    };
        }
  
        EventXmlParser::EventXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a FileImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            FileXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> FileXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeFilepath: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeFilepath(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<FileImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__FILEPATH, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetFilepath(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__FILEPATH, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__FILEPATH, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__FILEPATH, std::make_shared<AttributeFilepath>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> FileXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        FileXmlParser::FileXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a FileHeaderImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            FileHeaderXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> FileHeaderXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeAuthor: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeAuthor(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<FileHeaderImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__AUTHOR, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetAuthor(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__AUTHOR, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__AUTHOR, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__AUTHOR, std::make_shared<AttributeAuthor>(_messageLogger, _filename, _parserOptions)));
            class AttributeDate: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeDate(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<FileHeaderImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__DATE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetDate(ParseDateTime(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__DATE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__DATE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__DATE, std::make_shared<AttributeDate>(_messageLogger, _filename, _parserOptions)));
            class AttributeDescription: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeDescription(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<FileHeaderImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__DESCRIPTION, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetDescription(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__DESCRIPTION, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__DESCRIPTION, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__DESCRIPTION, std::make_shared<AttributeDescription>(_messageLogger, _filename, _parserOptions)));
            class AttributeRevMajor: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeRevMajor(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<FileHeaderImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__REV_MAJOR, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetRevMajor(ParseUnsignedShort(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__REV_MAJOR, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__REV_MAJOR, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__REV_MAJOR, std::make_shared<AttributeRevMajor>(_messageLogger, _filename, _parserOptions)));
            class AttributeRevMinor: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeRevMinor(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<FileHeaderImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__REV_MINOR, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetRevMinor(ParseUnsignedShort(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__REV_MINOR, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__REV_MINOR, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__REV_MINOR, std::make_shared<AttributeRevMinor>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> FileHeaderXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        FileHeaderXmlParser::FileHeaderXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a FinalSpeedImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            FinalSpeedXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> FinalSpeedXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> FinalSpeedXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementAbsoluteSpeedParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementRelativeSpeedToMasterParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        FinalSpeedXmlParser::SubElementAbsoluteSpeedParser::SubElementAbsoluteSpeedParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _absoluteSpeedXmlParser = std::make_shared<AbsoluteSpeedXmlParser>(messageLogger, filename, parserOptions);
        }

        void FinalSpeedXmlParser::SubElementAbsoluteSpeedParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto absoluteSpeed = std::make_shared<AbsoluteSpeedImpl>();
            auto typedObject = std::static_pointer_cast<FinalSpeedImpl>(object);                    
            // Setting the parent
            absoluteSpeed->SetParent(object);
            _absoluteSpeedXmlParser->ParseElement(indexedElement, parserContext, absoluteSpeed);

            typedObject->SetAbsoluteSpeed(absoluteSpeed);
        }
        
        int FinalSpeedXmlParser::SubElementAbsoluteSpeedParser::GetMinOccur() 
        {
            return 0;
        }

        int FinalSpeedXmlParser::SubElementAbsoluteSpeedParser::GetMaxOccur() 
        {
            return 1;
        }

        bool FinalSpeedXmlParser::SubElementAbsoluteSpeedParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ABSOLUTE_SPEED ;
        }

        std::vector<std::string> FinalSpeedXmlParser::SubElementAbsoluteSpeedParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ABSOLUTE_SPEED
                    };
        }
        FinalSpeedXmlParser::SubElementRelativeSpeedToMasterParser::SubElementRelativeSpeedToMasterParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _relativeSpeedToMasterXmlParser = std::make_shared<RelativeSpeedToMasterXmlParser>(messageLogger, filename, parserOptions);
        }

        void FinalSpeedXmlParser::SubElementRelativeSpeedToMasterParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto relativeSpeedToMaster = std::make_shared<RelativeSpeedToMasterImpl>();
            auto typedObject = std::static_pointer_cast<FinalSpeedImpl>(object);                    
            // Setting the parent
            relativeSpeedToMaster->SetParent(object);
            _relativeSpeedToMasterXmlParser->ParseElement(indexedElement, parserContext, relativeSpeedToMaster);

            typedObject->SetRelativeSpeedToMaster(relativeSpeedToMaster);
        }
        
        int FinalSpeedXmlParser::SubElementRelativeSpeedToMasterParser::GetMinOccur() 
        {
            return 0;
        }

        int FinalSpeedXmlParser::SubElementRelativeSpeedToMasterParser::GetMaxOccur() 
        {
            return 1;
        }

        bool FinalSpeedXmlParser::SubElementRelativeSpeedToMasterParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__RELATIVE_SPEED_TO_MASTER ;
        }

        std::vector<std::string> FinalSpeedXmlParser::SubElementRelativeSpeedToMasterParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__RELATIVE_SPEED_TO_MASTER
                    };
        }
  
        FinalSpeedXmlParser::FinalSpeedXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a FogImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            FogXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> FogXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeVisualRange: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeVisualRange(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<FogImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__VISUAL_RANGE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetVisualRange(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__VISUAL_RANGE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__VISUAL_RANGE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__VISUAL_RANGE, std::make_shared<AttributeVisualRange>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> FogXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementBoundingBoxParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        FogXmlParser::SubElementBoundingBoxParser::SubElementBoundingBoxParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _boundingBoxXmlParser = std::make_shared<BoundingBoxXmlParser>(messageLogger, filename, parserOptions);
        }

        void FogXmlParser::SubElementBoundingBoxParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto boundingBox = std::make_shared<BoundingBoxImpl>();
            auto typedObject = std::static_pointer_cast<FogImpl>(object);                    
            // Setting the parent
            boundingBox->SetParent(object);
            _boundingBoxXmlParser->ParseElement(indexedElement, parserContext, boundingBox);

            typedObject->SetBoundingBox(boundingBox);
        }
        
        int FogXmlParser::SubElementBoundingBoxParser::GetMinOccur() 
        {
            return 0;
        }

        int FogXmlParser::SubElementBoundingBoxParser::GetMaxOccur() 
        {
            return 1;
        }

        bool FogXmlParser::SubElementBoundingBoxParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__BOUNDING_BOX ;
        }

        std::vector<std::string> FogXmlParser::SubElementBoundingBoxParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__BOUNDING_BOX
                    };
        }
  
        FogXmlParser::FogXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a FollowTrajectoryActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            FollowTrajectoryActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> FollowTrajectoryActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> FollowTrajectoryActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementTrajectoryParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementCatalogReferenceParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementTimeReferenceParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementTrajectoryFollowingModeParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        FollowTrajectoryActionXmlParser::SubElementTrajectoryParser::SubElementTrajectoryParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _trajectoryXmlParser = std::make_shared<TrajectoryXmlParser>(messageLogger, filename, parserOptions);
        }

        void FollowTrajectoryActionXmlParser::SubElementTrajectoryParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto trajectory = std::make_shared<TrajectoryImpl>();
            auto typedObject = std::static_pointer_cast<FollowTrajectoryActionImpl>(object);                    
            // Setting the parent
            trajectory->SetParent(object);
            _trajectoryXmlParser->ParseElement(indexedElement, parserContext, trajectory);

            typedObject->SetTrajectory(trajectory);
        }
        
        int FollowTrajectoryActionXmlParser::SubElementTrajectoryParser::GetMinOccur() 
        {
            return 0;
        }

        int FollowTrajectoryActionXmlParser::SubElementTrajectoryParser::GetMaxOccur() 
        {
            return 1;
        }

        bool FollowTrajectoryActionXmlParser::SubElementTrajectoryParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__TRAJECTORY ;
        }

        std::vector<std::string> FollowTrajectoryActionXmlParser::SubElementTrajectoryParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__TRAJECTORY
                    };
        }
        FollowTrajectoryActionXmlParser::SubElementCatalogReferenceParser::SubElementCatalogReferenceParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _catalogReferenceXmlParser = std::make_shared<CatalogReferenceXmlParser>(messageLogger, filename, parserOptions);
        }

        void FollowTrajectoryActionXmlParser::SubElementCatalogReferenceParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto catalogReference = std::make_shared<CatalogReferenceImpl>();
            auto typedObject = std::static_pointer_cast<FollowTrajectoryActionImpl>(object);                    
            // Setting the parent
            catalogReference->SetParent(object);
            _catalogReferenceXmlParser->ParseElement(indexedElement, parserContext, catalogReference);

            typedObject->SetCatalogReference(catalogReference);
            std::dynamic_pointer_cast<CatalogReferenceParserContext>(parserContext)->AddCatalogReference(std::dynamic_pointer_cast<ICatalogReference>(catalogReference));
        }
        
        int FollowTrajectoryActionXmlParser::SubElementCatalogReferenceParser::GetMinOccur() 
        {
            return 0;
        }

        int FollowTrajectoryActionXmlParser::SubElementCatalogReferenceParser::GetMaxOccur() 
        {
            return 1;
        }

        bool FollowTrajectoryActionXmlParser::SubElementCatalogReferenceParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__CATALOG_REFERENCE ;
        }

        std::vector<std::string> FollowTrajectoryActionXmlParser::SubElementCatalogReferenceParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__CATALOG_REFERENCE
                    };
        }
        FollowTrajectoryActionXmlParser::SubElementTimeReferenceParser::SubElementTimeReferenceParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _timeReferenceXmlParser = std::make_shared<TimeReferenceXmlParser>(messageLogger, filename, parserOptions);
        }

        void FollowTrajectoryActionXmlParser::SubElementTimeReferenceParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto timeReference = std::make_shared<TimeReferenceImpl>();
            auto typedObject = std::static_pointer_cast<FollowTrajectoryActionImpl>(object);                    
            // Setting the parent
            timeReference->SetParent(object);
            _timeReferenceXmlParser->ParseElement(indexedElement, parserContext, timeReference);

            typedObject->SetTimeReference(timeReference);
        }
        
        int FollowTrajectoryActionXmlParser::SubElementTimeReferenceParser::GetMinOccur() 
        {
            return 1;
        }

        int FollowTrajectoryActionXmlParser::SubElementTimeReferenceParser::GetMaxOccur() 
        {
            return 1;
        }

        bool FollowTrajectoryActionXmlParser::SubElementTimeReferenceParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__TIME_REFERENCE ;
        }

        std::vector<std::string> FollowTrajectoryActionXmlParser::SubElementTimeReferenceParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__TIME_REFERENCE
                    };
        }
        FollowTrajectoryActionXmlParser::SubElementTrajectoryFollowingModeParser::SubElementTrajectoryFollowingModeParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _trajectoryFollowingModeXmlParser = std::make_shared<TrajectoryFollowingModeXmlParser>(messageLogger, filename, parserOptions);
        }

        void FollowTrajectoryActionXmlParser::SubElementTrajectoryFollowingModeParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto trajectoryFollowingMode = std::make_shared<TrajectoryFollowingModeImpl>();
            auto typedObject = std::static_pointer_cast<FollowTrajectoryActionImpl>(object);                    
            // Setting the parent
            trajectoryFollowingMode->SetParent(object);
            _trajectoryFollowingModeXmlParser->ParseElement(indexedElement, parserContext, trajectoryFollowingMode);

            typedObject->SetTrajectoryFollowingMode(trajectoryFollowingMode);
        }
        
        int FollowTrajectoryActionXmlParser::SubElementTrajectoryFollowingModeParser::GetMinOccur() 
        {
            return 1;
        }

        int FollowTrajectoryActionXmlParser::SubElementTrajectoryFollowingModeParser::GetMaxOccur() 
        {
            return 1;
        }

        bool FollowTrajectoryActionXmlParser::SubElementTrajectoryFollowingModeParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__TRAJECTORY_FOLLOWING_MODE ;
        }

        std::vector<std::string> FollowTrajectoryActionXmlParser::SubElementTrajectoryFollowingModeParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__TRAJECTORY_FOLLOWING_MODE
                    };
        }
  
        FollowTrajectoryActionXmlParser::FollowTrajectoryActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a GlobalActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            GlobalActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> GlobalActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> GlobalActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementEnvironmentActionParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementEntityActionParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementParameterActionParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementInfrastructureActionParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementTrafficActionParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        GlobalActionXmlParser::SubElementEnvironmentActionParser::SubElementEnvironmentActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _environmentActionXmlParser = std::make_shared<EnvironmentActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void GlobalActionXmlParser::SubElementEnvironmentActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto environmentAction = std::make_shared<EnvironmentActionImpl>();
            auto typedObject = std::static_pointer_cast<GlobalActionImpl>(object);                    
            // Setting the parent
            environmentAction->SetParent(object);
            _environmentActionXmlParser->ParseElement(indexedElement, parserContext, environmentAction);

            typedObject->SetEnvironmentAction(environmentAction);
        }
        
        int GlobalActionXmlParser::SubElementEnvironmentActionParser::GetMinOccur() 
        {
            return 0;
        }

        int GlobalActionXmlParser::SubElementEnvironmentActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool GlobalActionXmlParser::SubElementEnvironmentActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ENVIRONMENT_ACTION ;
        }

        std::vector<std::string> GlobalActionXmlParser::SubElementEnvironmentActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ENVIRONMENT_ACTION
                    };
        }
        GlobalActionXmlParser::SubElementEntityActionParser::SubElementEntityActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _entityActionXmlParser = std::make_shared<EntityActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void GlobalActionXmlParser::SubElementEntityActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto entityAction = std::make_shared<EntityActionImpl>();
            auto typedObject = std::static_pointer_cast<GlobalActionImpl>(object);                    
            // Setting the parent
            entityAction->SetParent(object);
            _entityActionXmlParser->ParseElement(indexedElement, parserContext, entityAction);

            typedObject->SetEntityAction(entityAction);
        }
        
        int GlobalActionXmlParser::SubElementEntityActionParser::GetMinOccur() 
        {
            return 0;
        }

        int GlobalActionXmlParser::SubElementEntityActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool GlobalActionXmlParser::SubElementEntityActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ENTITY_ACTION ;
        }

        std::vector<std::string> GlobalActionXmlParser::SubElementEntityActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ENTITY_ACTION
                    };
        }
        GlobalActionXmlParser::SubElementParameterActionParser::SubElementParameterActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _parameterActionXmlParser = std::make_shared<ParameterActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void GlobalActionXmlParser::SubElementParameterActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto parameterAction = std::make_shared<ParameterActionImpl>();
            auto typedObject = std::static_pointer_cast<GlobalActionImpl>(object);                    
            // Setting the parent
            parameterAction->SetParent(object);
            _parameterActionXmlParser->ParseElement(indexedElement, parserContext, parameterAction);

            typedObject->SetParameterAction(parameterAction);
        }
        
        int GlobalActionXmlParser::SubElementParameterActionParser::GetMinOccur() 
        {
            return 0;
        }

        int GlobalActionXmlParser::SubElementParameterActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool GlobalActionXmlParser::SubElementParameterActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__PARAMETER_ACTION ;
        }

        std::vector<std::string> GlobalActionXmlParser::SubElementParameterActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__PARAMETER_ACTION
                    };
        }
        GlobalActionXmlParser::SubElementInfrastructureActionParser::SubElementInfrastructureActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _infrastructureActionXmlParser = std::make_shared<InfrastructureActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void GlobalActionXmlParser::SubElementInfrastructureActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto infrastructureAction = std::make_shared<InfrastructureActionImpl>();
            auto typedObject = std::static_pointer_cast<GlobalActionImpl>(object);                    
            // Setting the parent
            infrastructureAction->SetParent(object);
            _infrastructureActionXmlParser->ParseElement(indexedElement, parserContext, infrastructureAction);

            typedObject->SetInfrastructureAction(infrastructureAction);
        }
        
        int GlobalActionXmlParser::SubElementInfrastructureActionParser::GetMinOccur() 
        {
            return 0;
        }

        int GlobalActionXmlParser::SubElementInfrastructureActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool GlobalActionXmlParser::SubElementInfrastructureActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__INFRASTRUCTURE_ACTION ;
        }

        std::vector<std::string> GlobalActionXmlParser::SubElementInfrastructureActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__INFRASTRUCTURE_ACTION
                    };
        }
        GlobalActionXmlParser::SubElementTrafficActionParser::SubElementTrafficActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _trafficActionXmlParser = std::make_shared<TrafficActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void GlobalActionXmlParser::SubElementTrafficActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto trafficAction = std::make_shared<TrafficActionImpl>();
            auto typedObject = std::static_pointer_cast<GlobalActionImpl>(object);                    
            // Setting the parent
            trafficAction->SetParent(object);
            _trafficActionXmlParser->ParseElement(indexedElement, parserContext, trafficAction);

            typedObject->SetTrafficAction(trafficAction);
        }
        
        int GlobalActionXmlParser::SubElementTrafficActionParser::GetMinOccur() 
        {
            return 0;
        }

        int GlobalActionXmlParser::SubElementTrafficActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool GlobalActionXmlParser::SubElementTrafficActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__TRAFFIC_ACTION ;
        }

        std::vector<std::string> GlobalActionXmlParser::SubElementTrafficActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__TRAFFIC_ACTION
                    };
        }
  
        GlobalActionXmlParser::GlobalActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a InRoutePositionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            InRoutePositionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> InRoutePositionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> InRoutePositionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementFromCurrentEntityParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementFromRoadCoordinatesParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementFromLaneCoordinatesParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        InRoutePositionXmlParser::SubElementFromCurrentEntityParser::SubElementFromCurrentEntityParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _positionOfCurrentEntityXmlParser = std::make_shared<PositionOfCurrentEntityXmlParser>(messageLogger, filename, parserOptions);
        }

        void InRoutePositionXmlParser::SubElementFromCurrentEntityParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto fromCurrentEntity = std::make_shared<PositionOfCurrentEntityImpl>();
            auto typedObject = std::static_pointer_cast<InRoutePositionImpl>(object);                    
            // Setting the parent
            fromCurrentEntity->SetParent(object);
            _positionOfCurrentEntityXmlParser->ParseElement(indexedElement, parserContext, fromCurrentEntity);

            typedObject->SetFromCurrentEntity(fromCurrentEntity);
        }
        
        int InRoutePositionXmlParser::SubElementFromCurrentEntityParser::GetMinOccur() 
        {
            return 0;
        }

        int InRoutePositionXmlParser::SubElementFromCurrentEntityParser::GetMaxOccur() 
        {
            return 1;
        }

        bool InRoutePositionXmlParser::SubElementFromCurrentEntityParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__FROM_CURRENT_ENTITY ;
        }

        std::vector<std::string> InRoutePositionXmlParser::SubElementFromCurrentEntityParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__FROM_CURRENT_ENTITY
                    };
        }
        InRoutePositionXmlParser::SubElementFromRoadCoordinatesParser::SubElementFromRoadCoordinatesParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _positionInRoadCoordinatesXmlParser = std::make_shared<PositionInRoadCoordinatesXmlParser>(messageLogger, filename, parserOptions);
        }

        void InRoutePositionXmlParser::SubElementFromRoadCoordinatesParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto fromRoadCoordinates = std::make_shared<PositionInRoadCoordinatesImpl>();
            auto typedObject = std::static_pointer_cast<InRoutePositionImpl>(object);                    
            // Setting the parent
            fromRoadCoordinates->SetParent(object);
            _positionInRoadCoordinatesXmlParser->ParseElement(indexedElement, parserContext, fromRoadCoordinates);

            typedObject->SetFromRoadCoordinates(fromRoadCoordinates);
        }
        
        int InRoutePositionXmlParser::SubElementFromRoadCoordinatesParser::GetMinOccur() 
        {
            return 0;
        }

        int InRoutePositionXmlParser::SubElementFromRoadCoordinatesParser::GetMaxOccur() 
        {
            return 1;
        }

        bool InRoutePositionXmlParser::SubElementFromRoadCoordinatesParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__FROM_ROAD_COORDINATES ;
        }

        std::vector<std::string> InRoutePositionXmlParser::SubElementFromRoadCoordinatesParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__FROM_ROAD_COORDINATES
                    };
        }
        InRoutePositionXmlParser::SubElementFromLaneCoordinatesParser::SubElementFromLaneCoordinatesParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _positionInLaneCoordinatesXmlParser = std::make_shared<PositionInLaneCoordinatesXmlParser>(messageLogger, filename, parserOptions);
        }

        void InRoutePositionXmlParser::SubElementFromLaneCoordinatesParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto fromLaneCoordinates = std::make_shared<PositionInLaneCoordinatesImpl>();
            auto typedObject = std::static_pointer_cast<InRoutePositionImpl>(object);                    
            // Setting the parent
            fromLaneCoordinates->SetParent(object);
            _positionInLaneCoordinatesXmlParser->ParseElement(indexedElement, parserContext, fromLaneCoordinates);

            typedObject->SetFromLaneCoordinates(fromLaneCoordinates);
        }
        
        int InRoutePositionXmlParser::SubElementFromLaneCoordinatesParser::GetMinOccur() 
        {
            return 0;
        }

        int InRoutePositionXmlParser::SubElementFromLaneCoordinatesParser::GetMaxOccur() 
        {
            return 1;
        }

        bool InRoutePositionXmlParser::SubElementFromLaneCoordinatesParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__FROM_LANE_COORDINATES ;
        }

        std::vector<std::string> InRoutePositionXmlParser::SubElementFromLaneCoordinatesParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__FROM_LANE_COORDINATES
                    };
        }
  
        InRoutePositionXmlParser::InRoutePositionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a InfrastructureActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            InfrastructureActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> InfrastructureActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> InfrastructureActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementTrafficSignalActionParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        InfrastructureActionXmlParser::SubElementTrafficSignalActionParser::SubElementTrafficSignalActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _trafficSignalActionXmlParser = std::make_shared<TrafficSignalActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void InfrastructureActionXmlParser::SubElementTrafficSignalActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto trafficSignalAction = std::make_shared<TrafficSignalActionImpl>();
            auto typedObject = std::static_pointer_cast<InfrastructureActionImpl>(object);                    
            // Setting the parent
            trafficSignalAction->SetParent(object);
            _trafficSignalActionXmlParser->ParseElement(indexedElement, parserContext, trafficSignalAction);

            typedObject->SetTrafficSignalAction(trafficSignalAction);
        }
        
        int InfrastructureActionXmlParser::SubElementTrafficSignalActionParser::GetMinOccur() 
        {
            return 1;
        }

        int InfrastructureActionXmlParser::SubElementTrafficSignalActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool InfrastructureActionXmlParser::SubElementTrafficSignalActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__TRAFFIC_SIGNAL_ACTION ;
        }

        std::vector<std::string> InfrastructureActionXmlParser::SubElementTrafficSignalActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__TRAFFIC_SIGNAL_ACTION
                    };
        }
  
        InfrastructureActionXmlParser::InfrastructureActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a InitImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            InitXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> InitXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> InitXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementActionsParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        InitXmlParser::SubElementActionsParser::SubElementActionsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _initActionsXmlParser = std::make_shared<InitActionsXmlParser>(messageLogger, filename, parserOptions);
        }

        void InitXmlParser::SubElementActionsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto actions = std::make_shared<InitActionsImpl>();
            auto typedObject = std::static_pointer_cast<InitImpl>(object);                    
            // Setting the parent
            actions->SetParent(object);
            _initActionsXmlParser->ParseElement(indexedElement, parserContext, actions);

            typedObject->SetActions(actions);
        }
        
        int InitXmlParser::SubElementActionsParser::GetMinOccur() 
        {
            return 1;
        }

        int InitXmlParser::SubElementActionsParser::GetMaxOccur() 
        {
            return 1;
        }

        bool InitXmlParser::SubElementActionsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ACTIONS ;
        }

        std::vector<std::string> InitXmlParser::SubElementActionsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ACTIONS
                    };
        }
  
        InitXmlParser::InitXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a InitActionsImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            InitActionsXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> InitActionsXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> InitActionsXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementGlobalActionsParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementUserDefinedActionsParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementPrivatesParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        InitActionsXmlParser::SubElementGlobalActionsParser::SubElementGlobalActionsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _globalActionXmlParser = std::make_shared<GlobalActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void InitActionsXmlParser::SubElementGlobalActionsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto globalActions = std::make_shared<GlobalActionImpl>();
            auto typedObject = std::static_pointer_cast<InitActionsImpl>(object);                    
            // Setting the parent
            globalActions->SetParent(object);
            _globalActionXmlParser->ParseElement(indexedElement, parserContext, globalActions);
            auto globalActionsList = typedObject->GetWriterGlobalActions();
            globalActionsList.push_back(globalActions);
            typedObject->SetGlobalActions(globalActionsList);
        }
        
        int InitActionsXmlParser::SubElementGlobalActionsParser::GetMinOccur() 
        {
            return 0;
        }

        int InitActionsXmlParser::SubElementGlobalActionsParser::GetMaxOccur() 
        {
            return -1;
        }

        bool InitActionsXmlParser::SubElementGlobalActionsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__GLOBAL_ACTION ;
        }

        std::vector<std::string> InitActionsXmlParser::SubElementGlobalActionsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__GLOBAL_ACTION
                    };
        }
        InitActionsXmlParser::SubElementUserDefinedActionsParser::SubElementUserDefinedActionsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _userDefinedActionXmlParser = std::make_shared<UserDefinedActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void InitActionsXmlParser::SubElementUserDefinedActionsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto userDefinedActions = std::make_shared<UserDefinedActionImpl>();
            auto typedObject = std::static_pointer_cast<InitActionsImpl>(object);                    
            // Setting the parent
            userDefinedActions->SetParent(object);
            _userDefinedActionXmlParser->ParseElement(indexedElement, parserContext, userDefinedActions);
            auto userDefinedActionsList = typedObject->GetWriterUserDefinedActions();
            userDefinedActionsList.push_back(userDefinedActions);
            typedObject->SetUserDefinedActions(userDefinedActionsList);
        }
        
        int InitActionsXmlParser::SubElementUserDefinedActionsParser::GetMinOccur() 
        {
            return 0;
        }

        int InitActionsXmlParser::SubElementUserDefinedActionsParser::GetMaxOccur() 
        {
            return -1;
        }

        bool InitActionsXmlParser::SubElementUserDefinedActionsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__USER_DEFINED_ACTION ;
        }

        std::vector<std::string> InitActionsXmlParser::SubElementUserDefinedActionsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__USER_DEFINED_ACTION
                    };
        }
        InitActionsXmlParser::SubElementPrivatesParser::SubElementPrivatesParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _privateXmlParser = std::make_shared<PrivateXmlParser>(messageLogger, filename, parserOptions);
        }

        void InitActionsXmlParser::SubElementPrivatesParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto privates = std::make_shared<PrivateImpl>();
            auto typedObject = std::static_pointer_cast<InitActionsImpl>(object);                    
            // Setting the parent
            privates->SetParent(object);
            _privateXmlParser->ParseElement(indexedElement, parserContext, privates);
            auto privatesList = typedObject->GetWriterPrivates();
            privatesList.push_back(privates);
            typedObject->SetPrivates(privatesList);
        }
        
        int InitActionsXmlParser::SubElementPrivatesParser::GetMinOccur() 
        {
            return 0;
        }

        int InitActionsXmlParser::SubElementPrivatesParser::GetMaxOccur() 
        {
            return -1;
        }

        bool InitActionsXmlParser::SubElementPrivatesParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__PRIVATE ;
        }

        std::vector<std::string> InitActionsXmlParser::SubElementPrivatesParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__PRIVATE
                    };
        }
  
        InitActionsXmlParser::InitActionsXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a KnotImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            KnotXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> KnotXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeValue: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeValue(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<KnotImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__VALUE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetValue(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<AttributeValue>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> KnotXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        KnotXmlParser::KnotXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a LaneChangeActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            LaneChangeActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> LaneChangeActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeTargetLaneOffset: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeTargetLaneOffset(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LaneChangeActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__TARGET_LANE_OFFSET, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetTargetLaneOffset(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__TARGET_LANE_OFFSET, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__TARGET_LANE_OFFSET, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__TARGET_LANE_OFFSET, std::make_shared<AttributeTargetLaneOffset>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> LaneChangeActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementLaneChangeActionDynamicsParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementLaneChangeTargetParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        LaneChangeActionXmlParser::SubElementLaneChangeActionDynamicsParser::SubElementLaneChangeActionDynamicsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _transitionDynamicsXmlParser = std::make_shared<TransitionDynamicsXmlParser>(messageLogger, filename, parserOptions);
        }

        void LaneChangeActionXmlParser::SubElementLaneChangeActionDynamicsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto laneChangeActionDynamics = std::make_shared<TransitionDynamicsImpl>();
            auto typedObject = std::static_pointer_cast<LaneChangeActionImpl>(object);                    
            // Setting the parent
            laneChangeActionDynamics->SetParent(object);
            _transitionDynamicsXmlParser->ParseElement(indexedElement, parserContext, laneChangeActionDynamics);

            typedObject->SetLaneChangeActionDynamics(laneChangeActionDynamics);
        }
        
        int LaneChangeActionXmlParser::SubElementLaneChangeActionDynamicsParser::GetMinOccur() 
        {
            return 1;
        }

        int LaneChangeActionXmlParser::SubElementLaneChangeActionDynamicsParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LaneChangeActionXmlParser::SubElementLaneChangeActionDynamicsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__LANE_CHANGE_ACTION_DYNAMICS ;
        }

        std::vector<std::string> LaneChangeActionXmlParser::SubElementLaneChangeActionDynamicsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__LANE_CHANGE_ACTION_DYNAMICS
                    };
        }
        LaneChangeActionXmlParser::SubElementLaneChangeTargetParser::SubElementLaneChangeTargetParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _laneChangeTargetXmlParser = std::make_shared<LaneChangeTargetXmlParser>(messageLogger, filename, parserOptions);
        }

        void LaneChangeActionXmlParser::SubElementLaneChangeTargetParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto laneChangeTarget = std::make_shared<LaneChangeTargetImpl>();
            auto typedObject = std::static_pointer_cast<LaneChangeActionImpl>(object);                    
            // Setting the parent
            laneChangeTarget->SetParent(object);
            _laneChangeTargetXmlParser->ParseElement(indexedElement, parserContext, laneChangeTarget);

            typedObject->SetLaneChangeTarget(laneChangeTarget);
        }
        
        int LaneChangeActionXmlParser::SubElementLaneChangeTargetParser::GetMinOccur() 
        {
            return 1;
        }

        int LaneChangeActionXmlParser::SubElementLaneChangeTargetParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LaneChangeActionXmlParser::SubElementLaneChangeTargetParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__LANE_CHANGE_TARGET ;
        }

        std::vector<std::string> LaneChangeActionXmlParser::SubElementLaneChangeTargetParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__LANE_CHANGE_TARGET
                    };
        }
  
        LaneChangeActionXmlParser::LaneChangeActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a LaneChangeTargetImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            LaneChangeTargetXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> LaneChangeTargetXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> LaneChangeTargetXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementRelativeTargetLaneParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementAbsoluteTargetLaneParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        LaneChangeTargetXmlParser::SubElementRelativeTargetLaneParser::SubElementRelativeTargetLaneParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _relativeTargetLaneXmlParser = std::make_shared<RelativeTargetLaneXmlParser>(messageLogger, filename, parserOptions);
        }

        void LaneChangeTargetXmlParser::SubElementRelativeTargetLaneParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto relativeTargetLane = std::make_shared<RelativeTargetLaneImpl>();
            auto typedObject = std::static_pointer_cast<LaneChangeTargetImpl>(object);                    
            // Setting the parent
            relativeTargetLane->SetParent(object);
            _relativeTargetLaneXmlParser->ParseElement(indexedElement, parserContext, relativeTargetLane);

            typedObject->SetRelativeTargetLane(relativeTargetLane);
        }
        
        int LaneChangeTargetXmlParser::SubElementRelativeTargetLaneParser::GetMinOccur() 
        {
            return 0;
        }

        int LaneChangeTargetXmlParser::SubElementRelativeTargetLaneParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LaneChangeTargetXmlParser::SubElementRelativeTargetLaneParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__RELATIVE_TARGET_LANE ;
        }

        std::vector<std::string> LaneChangeTargetXmlParser::SubElementRelativeTargetLaneParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__RELATIVE_TARGET_LANE
                    };
        }
        LaneChangeTargetXmlParser::SubElementAbsoluteTargetLaneParser::SubElementAbsoluteTargetLaneParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _absoluteTargetLaneXmlParser = std::make_shared<AbsoluteTargetLaneXmlParser>(messageLogger, filename, parserOptions);
        }

        void LaneChangeTargetXmlParser::SubElementAbsoluteTargetLaneParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto absoluteTargetLane = std::make_shared<AbsoluteTargetLaneImpl>();
            auto typedObject = std::static_pointer_cast<LaneChangeTargetImpl>(object);                    
            // Setting the parent
            absoluteTargetLane->SetParent(object);
            _absoluteTargetLaneXmlParser->ParseElement(indexedElement, parserContext, absoluteTargetLane);

            typedObject->SetAbsoluteTargetLane(absoluteTargetLane);
        }
        
        int LaneChangeTargetXmlParser::SubElementAbsoluteTargetLaneParser::GetMinOccur() 
        {
            return 0;
        }

        int LaneChangeTargetXmlParser::SubElementAbsoluteTargetLaneParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LaneChangeTargetXmlParser::SubElementAbsoluteTargetLaneParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ABSOLUTE_TARGET_LANE ;
        }

        std::vector<std::string> LaneChangeTargetXmlParser::SubElementAbsoluteTargetLaneParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ABSOLUTE_TARGET_LANE
                    };
        }
  
        LaneChangeTargetXmlParser::LaneChangeTargetXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a LaneOffsetActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            LaneOffsetActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> LaneOffsetActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeContinuous: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeContinuous(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LaneOffsetActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetContinuous(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, std::make_shared<AttributeContinuous>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> LaneOffsetActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementLaneOffsetActionDynamicsParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementLaneOffsetTargetParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        LaneOffsetActionXmlParser::SubElementLaneOffsetActionDynamicsParser::SubElementLaneOffsetActionDynamicsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _laneOffsetActionDynamicsXmlParser = std::make_shared<LaneOffsetActionDynamicsXmlParser>(messageLogger, filename, parserOptions);
        }

        void LaneOffsetActionXmlParser::SubElementLaneOffsetActionDynamicsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto laneOffsetActionDynamics = std::make_shared<LaneOffsetActionDynamicsImpl>();
            auto typedObject = std::static_pointer_cast<LaneOffsetActionImpl>(object);                    
            // Setting the parent
            laneOffsetActionDynamics->SetParent(object);
            _laneOffsetActionDynamicsXmlParser->ParseElement(indexedElement, parserContext, laneOffsetActionDynamics);

            typedObject->SetLaneOffsetActionDynamics(laneOffsetActionDynamics);
        }
        
        int LaneOffsetActionXmlParser::SubElementLaneOffsetActionDynamicsParser::GetMinOccur() 
        {
            return 1;
        }

        int LaneOffsetActionXmlParser::SubElementLaneOffsetActionDynamicsParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LaneOffsetActionXmlParser::SubElementLaneOffsetActionDynamicsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__LANE_OFFSET_ACTION_DYNAMICS ;
        }

        std::vector<std::string> LaneOffsetActionXmlParser::SubElementLaneOffsetActionDynamicsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__LANE_OFFSET_ACTION_DYNAMICS
                    };
        }
        LaneOffsetActionXmlParser::SubElementLaneOffsetTargetParser::SubElementLaneOffsetTargetParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _laneOffsetTargetXmlParser = std::make_shared<LaneOffsetTargetXmlParser>(messageLogger, filename, parserOptions);
        }

        void LaneOffsetActionXmlParser::SubElementLaneOffsetTargetParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto laneOffsetTarget = std::make_shared<LaneOffsetTargetImpl>();
            auto typedObject = std::static_pointer_cast<LaneOffsetActionImpl>(object);                    
            // Setting the parent
            laneOffsetTarget->SetParent(object);
            _laneOffsetTargetXmlParser->ParseElement(indexedElement, parserContext, laneOffsetTarget);

            typedObject->SetLaneOffsetTarget(laneOffsetTarget);
        }
        
        int LaneOffsetActionXmlParser::SubElementLaneOffsetTargetParser::GetMinOccur() 
        {
            return 1;
        }

        int LaneOffsetActionXmlParser::SubElementLaneOffsetTargetParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LaneOffsetActionXmlParser::SubElementLaneOffsetTargetParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__LANE_OFFSET_TARGET ;
        }

        std::vector<std::string> LaneOffsetActionXmlParser::SubElementLaneOffsetTargetParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__LANE_OFFSET_TARGET
                    };
        }
  
        LaneOffsetActionXmlParser::LaneOffsetActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a LaneOffsetActionDynamicsImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            LaneOffsetActionDynamicsXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> LaneOffsetActionDynamicsXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeDynamicsShape: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeDynamicsShape(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LaneOffsetActionDynamicsImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__DYNAMICS_SHAPE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Enumeration Type
                        const auto kResult = DynamicsShape::GetFromLiteral(attributeValue);
                        if (kResult != DynamicsShape::UNKNOWN)
                        {
                            typedObject->SetDynamicsShape(attributeValue);
                        }
                        else
                        {
                            auto msg = FileContentMessage("Value '" + attributeValue + "' is not allowed.", ERROR, startMarker);
                            _messageLogger.LogMessage(msg);
                        }
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__DYNAMICS_SHAPE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__DYNAMICS_SHAPE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__DYNAMICS_SHAPE, std::make_shared<AttributeDynamicsShape>(_messageLogger, _filename, _parserOptions)));
            class AttributeMaxLateralAcc: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeMaxLateralAcc(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LaneOffsetActionDynamicsImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__MAX_LATERAL_ACC, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetMaxLateralAcc(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__MAX_LATERAL_ACC, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__MAX_LATERAL_ACC, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__MAX_LATERAL_ACC, std::make_shared<AttributeMaxLateralAcc>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> LaneOffsetActionDynamicsXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        LaneOffsetActionDynamicsXmlParser::LaneOffsetActionDynamicsXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a LaneOffsetTargetImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            LaneOffsetTargetXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> LaneOffsetTargetXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> LaneOffsetTargetXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementRelativeTargetLaneOffsetParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementAbsoluteTargetLaneOffsetParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        LaneOffsetTargetXmlParser::SubElementRelativeTargetLaneOffsetParser::SubElementRelativeTargetLaneOffsetParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _relativeTargetLaneOffsetXmlParser = std::make_shared<RelativeTargetLaneOffsetXmlParser>(messageLogger, filename, parserOptions);
        }

        void LaneOffsetTargetXmlParser::SubElementRelativeTargetLaneOffsetParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto relativeTargetLaneOffset = std::make_shared<RelativeTargetLaneOffsetImpl>();
            auto typedObject = std::static_pointer_cast<LaneOffsetTargetImpl>(object);                    
            // Setting the parent
            relativeTargetLaneOffset->SetParent(object);
            _relativeTargetLaneOffsetXmlParser->ParseElement(indexedElement, parserContext, relativeTargetLaneOffset);

            typedObject->SetRelativeTargetLaneOffset(relativeTargetLaneOffset);
        }
        
        int LaneOffsetTargetXmlParser::SubElementRelativeTargetLaneOffsetParser::GetMinOccur() 
        {
            return 0;
        }

        int LaneOffsetTargetXmlParser::SubElementRelativeTargetLaneOffsetParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LaneOffsetTargetXmlParser::SubElementRelativeTargetLaneOffsetParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__RELATIVE_TARGET_LANE_OFFSET ;
        }

        std::vector<std::string> LaneOffsetTargetXmlParser::SubElementRelativeTargetLaneOffsetParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__RELATIVE_TARGET_LANE_OFFSET
                    };
        }
        LaneOffsetTargetXmlParser::SubElementAbsoluteTargetLaneOffsetParser::SubElementAbsoluteTargetLaneOffsetParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _absoluteTargetLaneOffsetXmlParser = std::make_shared<AbsoluteTargetLaneOffsetXmlParser>(messageLogger, filename, parserOptions);
        }

        void LaneOffsetTargetXmlParser::SubElementAbsoluteTargetLaneOffsetParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto absoluteTargetLaneOffset = std::make_shared<AbsoluteTargetLaneOffsetImpl>();
            auto typedObject = std::static_pointer_cast<LaneOffsetTargetImpl>(object);                    
            // Setting the parent
            absoluteTargetLaneOffset->SetParent(object);
            _absoluteTargetLaneOffsetXmlParser->ParseElement(indexedElement, parserContext, absoluteTargetLaneOffset);

            typedObject->SetAbsoluteTargetLaneOffset(absoluteTargetLaneOffset);
        }
        
        int LaneOffsetTargetXmlParser::SubElementAbsoluteTargetLaneOffsetParser::GetMinOccur() 
        {
            return 0;
        }

        int LaneOffsetTargetXmlParser::SubElementAbsoluteTargetLaneOffsetParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LaneOffsetTargetXmlParser::SubElementAbsoluteTargetLaneOffsetParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ABSOLUTE_TARGET_LANE_OFFSET ;
        }

        std::vector<std::string> LaneOffsetTargetXmlParser::SubElementAbsoluteTargetLaneOffsetParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ABSOLUTE_TARGET_LANE_OFFSET
                    };
        }
  
        LaneOffsetTargetXmlParser::LaneOffsetTargetXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a LanePositionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            LanePositionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> LanePositionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeLaneId: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeLaneId(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LanePositionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__LANE_ID, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetLaneId(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__LANE_ID, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__LANE_ID, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__LANE_ID, std::make_shared<AttributeLaneId>(_messageLogger, _filename, _parserOptions)));
            class AttributeOffset: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeOffset(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LanePositionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__OFFSET, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetOffset(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__OFFSET, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__OFFSET, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__OFFSET, std::make_shared<AttributeOffset>(_messageLogger, _filename, _parserOptions)));
            class AttributeRoadId: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeRoadId(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LanePositionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ROAD_ID, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetRoadId(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ROAD_ID, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ROAD_ID, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ROAD_ID, std::make_shared<AttributeRoadId>(_messageLogger, _filename, _parserOptions)));
            class AttributeS: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeS(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LanePositionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__S, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetS(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__S, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__S, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__S, std::make_shared<AttributeS>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> LanePositionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementOrientationParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        LanePositionXmlParser::SubElementOrientationParser::SubElementOrientationParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _orientationXmlParser = std::make_shared<OrientationXmlParser>(messageLogger, filename, parserOptions);
        }

        void LanePositionXmlParser::SubElementOrientationParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto orientation = std::make_shared<OrientationImpl>();
            auto typedObject = std::static_pointer_cast<LanePositionImpl>(object);                    
            // Setting the parent
            orientation->SetParent(object);
            _orientationXmlParser->ParseElement(indexedElement, parserContext, orientation);

            typedObject->SetOrientation(orientation);
        }
        
        int LanePositionXmlParser::SubElementOrientationParser::GetMinOccur() 
        {
            return 0;
        }

        int LanePositionXmlParser::SubElementOrientationParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LanePositionXmlParser::SubElementOrientationParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ORIENTATION ;
        }

        std::vector<std::string> LanePositionXmlParser::SubElementOrientationParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ORIENTATION
                    };
        }
  
        LanePositionXmlParser::LanePositionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a LateralActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            LateralActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> LateralActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> LateralActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementLaneChangeActionParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementLaneOffsetActionParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementLateralDistanceActionParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        LateralActionXmlParser::SubElementLaneChangeActionParser::SubElementLaneChangeActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _laneChangeActionXmlParser = std::make_shared<LaneChangeActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void LateralActionXmlParser::SubElementLaneChangeActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto laneChangeAction = std::make_shared<LaneChangeActionImpl>();
            auto typedObject = std::static_pointer_cast<LateralActionImpl>(object);                    
            // Setting the parent
            laneChangeAction->SetParent(object);
            _laneChangeActionXmlParser->ParseElement(indexedElement, parserContext, laneChangeAction);

            typedObject->SetLaneChangeAction(laneChangeAction);
        }
        
        int LateralActionXmlParser::SubElementLaneChangeActionParser::GetMinOccur() 
        {
            return 0;
        }

        int LateralActionXmlParser::SubElementLaneChangeActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LateralActionXmlParser::SubElementLaneChangeActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__LANE_CHANGE_ACTION ;
        }

        std::vector<std::string> LateralActionXmlParser::SubElementLaneChangeActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__LANE_CHANGE_ACTION
                    };
        }
        LateralActionXmlParser::SubElementLaneOffsetActionParser::SubElementLaneOffsetActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _laneOffsetActionXmlParser = std::make_shared<LaneOffsetActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void LateralActionXmlParser::SubElementLaneOffsetActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto laneOffsetAction = std::make_shared<LaneOffsetActionImpl>();
            auto typedObject = std::static_pointer_cast<LateralActionImpl>(object);                    
            // Setting the parent
            laneOffsetAction->SetParent(object);
            _laneOffsetActionXmlParser->ParseElement(indexedElement, parserContext, laneOffsetAction);

            typedObject->SetLaneOffsetAction(laneOffsetAction);
        }
        
        int LateralActionXmlParser::SubElementLaneOffsetActionParser::GetMinOccur() 
        {
            return 0;
        }

        int LateralActionXmlParser::SubElementLaneOffsetActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LateralActionXmlParser::SubElementLaneOffsetActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__LANE_OFFSET_ACTION ;
        }

        std::vector<std::string> LateralActionXmlParser::SubElementLaneOffsetActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__LANE_OFFSET_ACTION
                    };
        }
        LateralActionXmlParser::SubElementLateralDistanceActionParser::SubElementLateralDistanceActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _lateralDistanceActionXmlParser = std::make_shared<LateralDistanceActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void LateralActionXmlParser::SubElementLateralDistanceActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto lateralDistanceAction = std::make_shared<LateralDistanceActionImpl>();
            auto typedObject = std::static_pointer_cast<LateralActionImpl>(object);                    
            // Setting the parent
            lateralDistanceAction->SetParent(object);
            _lateralDistanceActionXmlParser->ParseElement(indexedElement, parserContext, lateralDistanceAction);

            typedObject->SetLateralDistanceAction(lateralDistanceAction);
        }
        
        int LateralActionXmlParser::SubElementLateralDistanceActionParser::GetMinOccur() 
        {
            return 0;
        }

        int LateralActionXmlParser::SubElementLateralDistanceActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LateralActionXmlParser::SubElementLateralDistanceActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__LATERAL_DISTANCE_ACTION ;
        }

        std::vector<std::string> LateralActionXmlParser::SubElementLateralDistanceActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__LATERAL_DISTANCE_ACTION
                    };
        }
  
        LateralActionXmlParser::LateralActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a LateralDistanceActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            LateralDistanceActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> LateralDistanceActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeContinuous: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeContinuous(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LateralDistanceActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetContinuous(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, std::make_shared<AttributeContinuous>(_messageLogger, _filename, _parserOptions)));
            class AttributeDistance: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeDistance(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LateralDistanceActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__DISTANCE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetDistance(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__DISTANCE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__DISTANCE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__DISTANCE, std::make_shared<AttributeDistance>(_messageLogger, _filename, _parserOptions)));
            class AttributeEntityRef: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeEntityRef(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LateralDistanceActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Proxy
                        auto proxy = std::make_shared<NamedReferenceProxy<IEntity>>(attributeValue);
                        proxy->SetParent(typedObject);
                        typedObject->SetEntityRef(proxy);
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, std::make_shared<AttributeEntityRef>(_messageLogger, _filename, _parserOptions)));
            class AttributeFreespace: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeFreespace(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LateralDistanceActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__FREESPACE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetFreespace(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__FREESPACE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__FREESPACE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__FREESPACE, std::make_shared<AttributeFreespace>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> LateralDistanceActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementDynamicConstraintsParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        LateralDistanceActionXmlParser::SubElementDynamicConstraintsParser::SubElementDynamicConstraintsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _dynamicConstraintsXmlParser = std::make_shared<DynamicConstraintsXmlParser>(messageLogger, filename, parserOptions);
        }

        void LateralDistanceActionXmlParser::SubElementDynamicConstraintsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto dynamicConstraints = std::make_shared<DynamicConstraintsImpl>();
            auto typedObject = std::static_pointer_cast<LateralDistanceActionImpl>(object);                    
            // Setting the parent
            dynamicConstraints->SetParent(object);
            _dynamicConstraintsXmlParser->ParseElement(indexedElement, parserContext, dynamicConstraints);

            typedObject->SetDynamicConstraints(dynamicConstraints);
        }
        
        int LateralDistanceActionXmlParser::SubElementDynamicConstraintsParser::GetMinOccur() 
        {
            return 0;
        }

        int LateralDistanceActionXmlParser::SubElementDynamicConstraintsParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LateralDistanceActionXmlParser::SubElementDynamicConstraintsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__DYNAMIC_CONSTRAINTS ;
        }

        std::vector<std::string> LateralDistanceActionXmlParser::SubElementDynamicConstraintsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__DYNAMIC_CONSTRAINTS
                    };
        }
  
        LateralDistanceActionXmlParser::LateralDistanceActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a LongitudinalActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            LongitudinalActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> LongitudinalActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> LongitudinalActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementSpeedActionParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementLongitudinalDistanceActionParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        LongitudinalActionXmlParser::SubElementSpeedActionParser::SubElementSpeedActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _speedActionXmlParser = std::make_shared<SpeedActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void LongitudinalActionXmlParser::SubElementSpeedActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto speedAction = std::make_shared<SpeedActionImpl>();
            auto typedObject = std::static_pointer_cast<LongitudinalActionImpl>(object);                    
            // Setting the parent
            speedAction->SetParent(object);
            _speedActionXmlParser->ParseElement(indexedElement, parserContext, speedAction);

            typedObject->SetSpeedAction(speedAction);
        }
        
        int LongitudinalActionXmlParser::SubElementSpeedActionParser::GetMinOccur() 
        {
            return 0;
        }

        int LongitudinalActionXmlParser::SubElementSpeedActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LongitudinalActionXmlParser::SubElementSpeedActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__SPEED_ACTION ;
        }

        std::vector<std::string> LongitudinalActionXmlParser::SubElementSpeedActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__SPEED_ACTION
                    };
        }
        LongitudinalActionXmlParser::SubElementLongitudinalDistanceActionParser::SubElementLongitudinalDistanceActionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _longitudinalDistanceActionXmlParser = std::make_shared<LongitudinalDistanceActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void LongitudinalActionXmlParser::SubElementLongitudinalDistanceActionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto longitudinalDistanceAction = std::make_shared<LongitudinalDistanceActionImpl>();
            auto typedObject = std::static_pointer_cast<LongitudinalActionImpl>(object);                    
            // Setting the parent
            longitudinalDistanceAction->SetParent(object);
            _longitudinalDistanceActionXmlParser->ParseElement(indexedElement, parserContext, longitudinalDistanceAction);

            typedObject->SetLongitudinalDistanceAction(longitudinalDistanceAction);
        }
        
        int LongitudinalActionXmlParser::SubElementLongitudinalDistanceActionParser::GetMinOccur() 
        {
            return 0;
        }

        int LongitudinalActionXmlParser::SubElementLongitudinalDistanceActionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LongitudinalActionXmlParser::SubElementLongitudinalDistanceActionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__LONGITUDINAL_DISTANCE_ACTION ;
        }

        std::vector<std::string> LongitudinalActionXmlParser::SubElementLongitudinalDistanceActionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__LONGITUDINAL_DISTANCE_ACTION
                    };
        }
  
        LongitudinalActionXmlParser::LongitudinalActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a LongitudinalDistanceActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            LongitudinalDistanceActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> LongitudinalDistanceActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeContinuous: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeContinuous(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LongitudinalDistanceActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetContinuous(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__CONTINUOUS, std::make_shared<AttributeContinuous>(_messageLogger, _filename, _parserOptions)));
            class AttributeDistance: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeDistance(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LongitudinalDistanceActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__DISTANCE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetDistance(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__DISTANCE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__DISTANCE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__DISTANCE, std::make_shared<AttributeDistance>(_messageLogger, _filename, _parserOptions)));
            class AttributeEntityRef: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeEntityRef(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LongitudinalDistanceActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Proxy
                        auto proxy = std::make_shared<NamedReferenceProxy<IEntity>>(attributeValue);
                        proxy->SetParent(typedObject);
                        typedObject->SetEntityRef(proxy);
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ENTITY_REF, std::make_shared<AttributeEntityRef>(_messageLogger, _filename, _parserOptions)));
            class AttributeFreespace: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeFreespace(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LongitudinalDistanceActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__FREESPACE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetFreespace(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__FREESPACE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__FREESPACE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__FREESPACE, std::make_shared<AttributeFreespace>(_messageLogger, _filename, _parserOptions)));
            class AttributeTimeGap: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeTimeGap(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<LongitudinalDistanceActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__TIME_GAP, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetTimeGap(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__TIME_GAP, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__TIME_GAP, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__TIME_GAP, std::make_shared<AttributeTimeGap>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> LongitudinalDistanceActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementDynamicConstraintsParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        LongitudinalDistanceActionXmlParser::SubElementDynamicConstraintsParser::SubElementDynamicConstraintsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _dynamicConstraintsXmlParser = std::make_shared<DynamicConstraintsXmlParser>(messageLogger, filename, parserOptions);
        }

        void LongitudinalDistanceActionXmlParser::SubElementDynamicConstraintsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto dynamicConstraints = std::make_shared<DynamicConstraintsImpl>();
            auto typedObject = std::static_pointer_cast<LongitudinalDistanceActionImpl>(object);                    
            // Setting the parent
            dynamicConstraints->SetParent(object);
            _dynamicConstraintsXmlParser->ParseElement(indexedElement, parserContext, dynamicConstraints);

            typedObject->SetDynamicConstraints(dynamicConstraints);
        }
        
        int LongitudinalDistanceActionXmlParser::SubElementDynamicConstraintsParser::GetMinOccur() 
        {
            return 0;
        }

        int LongitudinalDistanceActionXmlParser::SubElementDynamicConstraintsParser::GetMaxOccur() 
        {
            return 1;
        }

        bool LongitudinalDistanceActionXmlParser::SubElementDynamicConstraintsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__DYNAMIC_CONSTRAINTS ;
        }

        std::vector<std::string> LongitudinalDistanceActionXmlParser::SubElementDynamicConstraintsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__DYNAMIC_CONSTRAINTS
                    };
        }
  
        LongitudinalDistanceActionXmlParser::LongitudinalDistanceActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a ManeuverImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            ManeuverXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> ManeuverXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeName: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeName(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<ManeuverImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__NAME, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetName(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<AttributeName>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> ManeuverXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<WrappedListParser>(_messageLogger, _filename, std::make_shared<SubElementParameterDeclarationsParser>(_messageLogger, _filename, _parserOptions), OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATIONS, _parserOptions) );
            result.push_back(std::make_shared<SubElementEventsParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        ManeuverXmlParser::SubElementParameterDeclarationsParser::SubElementParameterDeclarationsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _parameterDeclarationXmlParser = std::make_shared<ParameterDeclarationXmlParser>(messageLogger, filename, parserOptions);
        }

        void ManeuverXmlParser::SubElementParameterDeclarationsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto parameterDeclarations = std::make_shared<ParameterDeclarationImpl>();
            auto typedObject = std::static_pointer_cast<ManeuverImpl>(object);                    
            // Setting the parent
            parameterDeclarations->SetParent(object);
            _parameterDeclarationXmlParser->ParseElement(indexedElement, parserContext, parameterDeclarations);
            auto parameterDeclarationsList = typedObject->GetWriterParameterDeclarations();
            parameterDeclarationsList.push_back(parameterDeclarations);
            typedObject->SetParameterDeclarations(parameterDeclarationsList);
        }
        
        int ManeuverXmlParser::SubElementParameterDeclarationsParser::GetMinOccur() 
        {
            return 0;
        }

        int ManeuverXmlParser::SubElementParameterDeclarationsParser::GetMaxOccur() 
        {
            return -1;
        }

        bool ManeuverXmlParser::SubElementParameterDeclarationsParser::DoesMatch(std::string& elementName)
        {
            return elementName == OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATION;
        }

        std::vector<std::string> ManeuverXmlParser::SubElementParameterDeclarationsParser::GetExpectedTagNames()
        {
            return {OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATION};
        }
        ManeuverXmlParser::SubElementEventsParser::SubElementEventsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _eventXmlParser = std::make_shared<EventXmlParser>(messageLogger, filename, parserOptions);
        }

        void ManeuverXmlParser::SubElementEventsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto events = std::make_shared<EventImpl>();
            auto typedObject = std::static_pointer_cast<ManeuverImpl>(object);                    
            // Setting the parent
            events->SetParent(object);
            _eventXmlParser->ParseElement(indexedElement, parserContext, events);
            auto eventsList = typedObject->GetWriterEvents();
            eventsList.push_back(events);
            typedObject->SetEvents(eventsList);
        }
        
        int ManeuverXmlParser::SubElementEventsParser::GetMinOccur() 
        {
            return 1;
        }

        int ManeuverXmlParser::SubElementEventsParser::GetMaxOccur() 
        {
            return -1;
        }

        bool ManeuverXmlParser::SubElementEventsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__EVENT ;
        }

        std::vector<std::string> ManeuverXmlParser::SubElementEventsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__EVENT
                    };
        }
  
        ManeuverXmlParser::ManeuverXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a ManeuverCatalogLocationImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            ManeuverCatalogLocationXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> ManeuverCatalogLocationXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> ManeuverCatalogLocationXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementDirectoryParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        ManeuverCatalogLocationXmlParser::SubElementDirectoryParser::SubElementDirectoryParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _directoryXmlParser = std::make_shared<DirectoryXmlParser>(messageLogger, filename, parserOptions);
        }

        void ManeuverCatalogLocationXmlParser::SubElementDirectoryParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto directory = std::make_shared<DirectoryImpl>();
            auto typedObject = std::static_pointer_cast<ManeuverCatalogLocationImpl>(object);                    
            // Setting the parent
            directory->SetParent(object);
            _directoryXmlParser->ParseElement(indexedElement, parserContext, directory);

            typedObject->SetDirectory(directory);
        }
        
        int ManeuverCatalogLocationXmlParser::SubElementDirectoryParser::GetMinOccur() 
        {
            return 1;
        }

        int ManeuverCatalogLocationXmlParser::SubElementDirectoryParser::GetMaxOccur() 
        {
            return 1;
        }

        bool ManeuverCatalogLocationXmlParser::SubElementDirectoryParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__DIRECTORY ;
        }

        std::vector<std::string> ManeuverCatalogLocationXmlParser::SubElementDirectoryParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__DIRECTORY
                    };
        }
  
        ManeuverCatalogLocationXmlParser::ManeuverCatalogLocationXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a ManeuverGroupImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            ManeuverGroupXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> ManeuverGroupXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeMaximumExecutionCount: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeMaximumExecutionCount(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<ManeuverGroupImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__MAXIMUM_EXECUTION_COUNT, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetMaximumExecutionCount(ParseUnsignedInt(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__MAXIMUM_EXECUTION_COUNT, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__MAXIMUM_EXECUTION_COUNT, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__MAXIMUM_EXECUTION_COUNT, std::make_shared<AttributeMaximumExecutionCount>(_messageLogger, _filename, _parserOptions)));
            class AttributeName: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeName(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<ManeuverGroupImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__NAME, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetName(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<AttributeName>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> ManeuverGroupXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementActorsParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementCatalogReferencesParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementManeuversParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        ManeuverGroupXmlParser::SubElementActorsParser::SubElementActorsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _actorsXmlParser = std::make_shared<ActorsXmlParser>(messageLogger, filename, parserOptions);
        }

        void ManeuverGroupXmlParser::SubElementActorsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto actors = std::make_shared<ActorsImpl>();
            auto typedObject = std::static_pointer_cast<ManeuverGroupImpl>(object);                    
            // Setting the parent
            actors->SetParent(object);
            _actorsXmlParser->ParseElement(indexedElement, parserContext, actors);

            typedObject->SetActors(actors);
        }
        
        int ManeuverGroupXmlParser::SubElementActorsParser::GetMinOccur() 
        {
            return 1;
        }

        int ManeuverGroupXmlParser::SubElementActorsParser::GetMaxOccur() 
        {
            return 1;
        }

        bool ManeuverGroupXmlParser::SubElementActorsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ACTORS ;
        }

        std::vector<std::string> ManeuverGroupXmlParser::SubElementActorsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ACTORS
                    };
        }
        ManeuverGroupXmlParser::SubElementCatalogReferencesParser::SubElementCatalogReferencesParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _catalogReferenceXmlParser = std::make_shared<CatalogReferenceXmlParser>(messageLogger, filename, parserOptions);
        }

        void ManeuverGroupXmlParser::SubElementCatalogReferencesParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto catalogReferences = std::make_shared<CatalogReferenceImpl>();
            auto typedObject = std::static_pointer_cast<ManeuverGroupImpl>(object);                    
            // Setting the parent
            catalogReferences->SetParent(object);
            _catalogReferenceXmlParser->ParseElement(indexedElement, parserContext, catalogReferences);
            auto catalogReferencesList = typedObject->GetWriterCatalogReferences();
            catalogReferencesList.push_back(catalogReferences);
            typedObject->SetCatalogReferences(catalogReferencesList);
            std::dynamic_pointer_cast<CatalogReferenceParserContext>(parserContext)->AddCatalogReference(std::dynamic_pointer_cast<ICatalogReference>(catalogReferences));
        }
        
        int ManeuverGroupXmlParser::SubElementCatalogReferencesParser::GetMinOccur() 
        {
            return 0;
        }

        int ManeuverGroupXmlParser::SubElementCatalogReferencesParser::GetMaxOccur() 
        {
            return -1;
        }

        bool ManeuverGroupXmlParser::SubElementCatalogReferencesParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__CATALOG_REFERENCE ;
        }

        std::vector<std::string> ManeuverGroupXmlParser::SubElementCatalogReferencesParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__CATALOG_REFERENCE
                    };
        }
        ManeuverGroupXmlParser::SubElementManeuversParser::SubElementManeuversParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _maneuverXmlParser = std::make_shared<ManeuverXmlParser>(messageLogger, filename, parserOptions);
        }

        void ManeuverGroupXmlParser::SubElementManeuversParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto maneuvers = std::make_shared<ManeuverImpl>();
            auto typedObject = std::static_pointer_cast<ManeuverGroupImpl>(object);                    
            // Setting the parent
            maneuvers->SetParent(object);
            _maneuverXmlParser->ParseElement(indexedElement, parserContext, maneuvers);
            auto maneuversList = typedObject->GetWriterManeuvers();
            maneuversList.push_back(maneuvers);
            typedObject->SetManeuvers(maneuversList);
        }
        
        int ManeuverGroupXmlParser::SubElementManeuversParser::GetMinOccur() 
        {
            return 0;
        }

        int ManeuverGroupXmlParser::SubElementManeuversParser::GetMaxOccur() 
        {
            return -1;
        }

        bool ManeuverGroupXmlParser::SubElementManeuversParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__MANEUVER ;
        }

        std::vector<std::string> ManeuverGroupXmlParser::SubElementManeuversParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__MANEUVER
                    };
        }
  
        ManeuverGroupXmlParser::ManeuverGroupXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a MiscObjectImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            MiscObjectXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> MiscObjectXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeMass: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeMass(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<MiscObjectImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__MASS, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetMass(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__MASS, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__MASS, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__MASS, std::make_shared<AttributeMass>(_messageLogger, _filename, _parserOptions)));
            class AttributeMiscObjectCategory: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeMiscObjectCategory(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<MiscObjectImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__MISC_OBJECT_CATEGORY, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Enumeration Type
                        const auto kResult = MiscObjectCategory::GetFromLiteral(attributeValue);
                        if (kResult != MiscObjectCategory::UNKNOWN)
                        {
                            typedObject->SetMiscObjectCategory(attributeValue);
                        }
                        else
                        {
                            auto msg = FileContentMessage("Value '" + attributeValue + "' is not allowed.", ERROR, startMarker);
                            _messageLogger.LogMessage(msg);
                        }
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__MISC_OBJECT_CATEGORY, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__MISC_OBJECT_CATEGORY, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__MISC_OBJECT_CATEGORY, std::make_shared<AttributeMiscObjectCategory>(_messageLogger, _filename, _parserOptions)));
            class AttributeName: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeName(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<MiscObjectImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__NAME, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetName(ParseString(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__NAME, std::make_shared<AttributeName>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> MiscObjectXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<WrappedListParser>(_messageLogger, _filename, std::make_shared<SubElementParameterDeclarationsParser>(_messageLogger, _filename, _parserOptions), OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATIONS, _parserOptions) );
            result.push_back(std::make_shared<SubElementBoundingBoxParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementPropertiesParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        MiscObjectXmlParser::SubElementParameterDeclarationsParser::SubElementParameterDeclarationsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _parameterDeclarationXmlParser = std::make_shared<ParameterDeclarationXmlParser>(messageLogger, filename, parserOptions);
        }

        void MiscObjectXmlParser::SubElementParameterDeclarationsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto parameterDeclarations = std::make_shared<ParameterDeclarationImpl>();
            auto typedObject = std::static_pointer_cast<MiscObjectImpl>(object);                    
            // Setting the parent
            parameterDeclarations->SetParent(object);
            _parameterDeclarationXmlParser->ParseElement(indexedElement, parserContext, parameterDeclarations);
            auto parameterDeclarationsList = typedObject->GetWriterParameterDeclarations();
            parameterDeclarationsList.push_back(parameterDeclarations);
            typedObject->SetParameterDeclarations(parameterDeclarationsList);
        }
        
        int MiscObjectXmlParser::SubElementParameterDeclarationsParser::GetMinOccur() 
        {
            return 0;
        }

        int MiscObjectXmlParser::SubElementParameterDeclarationsParser::GetMaxOccur() 
        {
            return -1;
        }

        bool MiscObjectXmlParser::SubElementParameterDeclarationsParser::DoesMatch(std::string& elementName)
        {
            return elementName == OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATION;
        }

        std::vector<std::string> MiscObjectXmlParser::SubElementParameterDeclarationsParser::GetExpectedTagNames()
        {
            return {OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATION};
        }
        MiscObjectXmlParser::SubElementBoundingBoxParser::SubElementBoundingBoxParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _boundingBoxXmlParser = std::make_shared<BoundingBoxXmlParser>(messageLogger, filename, parserOptions);
        }

        void MiscObjectXmlParser::SubElementBoundingBoxParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto boundingBox = std::make_shared<BoundingBoxImpl>();
            auto typedObject = std::static_pointer_cast<MiscObjectImpl>(object);                    
            // Setting the parent
            boundingBox->SetParent(object);
            _boundingBoxXmlParser->ParseElement(indexedElement, parserContext, boundingBox);

            typedObject->SetBoundingBox(boundingBox);
        }
        
        int MiscObjectXmlParser::SubElementBoundingBoxParser::GetMinOccur() 
        {
            return 1;
        }

        int MiscObjectXmlParser::SubElementBoundingBoxParser::GetMaxOccur() 
        {
            return 1;
        }

        bool MiscObjectXmlParser::SubElementBoundingBoxParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__BOUNDING_BOX ;
        }

        std::vector<std::string> MiscObjectXmlParser::SubElementBoundingBoxParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__BOUNDING_BOX
                    };
        }
        MiscObjectXmlParser::SubElementPropertiesParser::SubElementPropertiesParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _propertiesXmlParser = std::make_shared<PropertiesXmlParser>(messageLogger, filename, parserOptions);
        }

        void MiscObjectXmlParser::SubElementPropertiesParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto properties = std::make_shared<PropertiesImpl>();
            auto typedObject = std::static_pointer_cast<MiscObjectImpl>(object);                    
            // Setting the parent
            properties->SetParent(object);
            _propertiesXmlParser->ParseElement(indexedElement, parserContext, properties);

            typedObject->SetProperties(properties);
        }
        
        int MiscObjectXmlParser::SubElementPropertiesParser::GetMinOccur() 
        {
            return 1;
        }

        int MiscObjectXmlParser::SubElementPropertiesParser::GetMaxOccur() 
        {
            return 1;
        }

        bool MiscObjectXmlParser::SubElementPropertiesParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__PROPERTIES ;
        }

        std::vector<std::string> MiscObjectXmlParser::SubElementPropertiesParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__PROPERTIES
                    };
        }
  
        MiscObjectXmlParser::MiscObjectXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a MiscObjectCatalogLocationImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            MiscObjectCatalogLocationXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> MiscObjectCatalogLocationXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> MiscObjectCatalogLocationXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementDirectoryParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        MiscObjectCatalogLocationXmlParser::SubElementDirectoryParser::SubElementDirectoryParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _directoryXmlParser = std::make_shared<DirectoryXmlParser>(messageLogger, filename, parserOptions);
        }

        void MiscObjectCatalogLocationXmlParser::SubElementDirectoryParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto directory = std::make_shared<DirectoryImpl>();
            auto typedObject = std::static_pointer_cast<MiscObjectCatalogLocationImpl>(object);                    
            // Setting the parent
            directory->SetParent(object);
            _directoryXmlParser->ParseElement(indexedElement, parserContext, directory);

            typedObject->SetDirectory(directory);
        }
        
        int MiscObjectCatalogLocationXmlParser::SubElementDirectoryParser::GetMinOccur() 
        {
            return 1;
        }

        int MiscObjectCatalogLocationXmlParser::SubElementDirectoryParser::GetMaxOccur() 
        {
            return 1;
        }

        bool MiscObjectCatalogLocationXmlParser::SubElementDirectoryParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__DIRECTORY ;
        }

        std::vector<std::string> MiscObjectCatalogLocationXmlParser::SubElementDirectoryParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__DIRECTORY
                    };
        }
  
        MiscObjectCatalogLocationXmlParser::MiscObjectCatalogLocationXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a ModifyRuleImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            ModifyRuleXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> ModifyRuleXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> ModifyRuleXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementAddValueParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementMultiplyByValueParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        ModifyRuleXmlParser::SubElementAddValueParser::SubElementAddValueParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _parameterAddValueRuleXmlParser = std::make_shared<ParameterAddValueRuleXmlParser>(messageLogger, filename, parserOptions);
        }

        void ModifyRuleXmlParser::SubElementAddValueParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto addValue = std::make_shared<ParameterAddValueRuleImpl>();
            auto typedObject = std::static_pointer_cast<ModifyRuleImpl>(object);                    
            // Setting the parent
            addValue->SetParent(object);
            _parameterAddValueRuleXmlParser->ParseElement(indexedElement, parserContext, addValue);

            typedObject->SetAddValue(addValue);
        }
        
        int ModifyRuleXmlParser::SubElementAddValueParser::GetMinOccur() 
        {
            return 0;
        }

        int ModifyRuleXmlParser::SubElementAddValueParser::GetMaxOccur() 
        {
            return 1;
        }

        bool ModifyRuleXmlParser::SubElementAddValueParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__ADD_VALUE ;
        }

        std::vector<std::string> ModifyRuleXmlParser::SubElementAddValueParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__ADD_VALUE
                    };
        }
        ModifyRuleXmlParser::SubElementMultiplyByValueParser::SubElementMultiplyByValueParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _parameterMultiplyByValueRuleXmlParser = std::make_shared<ParameterMultiplyByValueRuleXmlParser>(messageLogger, filename, parserOptions);
        }

        void ModifyRuleXmlParser::SubElementMultiplyByValueParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto multiplyByValue = std::make_shared<ParameterMultiplyByValueRuleImpl>();
            auto typedObject = std::static_pointer_cast<ModifyRuleImpl>(object);                    
            // Setting the parent
            multiplyByValue->SetParent(object);
            _parameterMultiplyByValueRuleXmlParser->ParseElement(indexedElement, parserContext, multiplyByValue);

            typedObject->SetMultiplyByValue(multiplyByValue);
        }
        
        int ModifyRuleXmlParser::SubElementMultiplyByValueParser::GetMinOccur() 
        {
            return 0;
        }

        int ModifyRuleXmlParser::SubElementMultiplyByValueParser::GetMaxOccur() 
        {
            return 1;
        }

        bool ModifyRuleXmlParser::SubElementMultiplyByValueParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__MULTIPLY_BY_VALUE ;
        }

        std::vector<std::string> ModifyRuleXmlParser::SubElementMultiplyByValueParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__MULTIPLY_BY_VALUE
                    };
        }
  
        ModifyRuleXmlParser::ModifyRuleXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a NoneImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            NoneXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> NoneXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> NoneXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        NoneXmlParser::NoneXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a NurbsImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            NurbsXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> NurbsXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeOrder: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeOrder(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<NurbsImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ORDER, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetOrder(ParseUnsignedInt(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ORDER, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ORDER, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ORDER, std::make_shared<AttributeOrder>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> NurbsXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementControlPointsParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementKnotsParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        NurbsXmlParser::SubElementControlPointsParser::SubElementControlPointsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _controlPointXmlParser = std::make_shared<ControlPointXmlParser>(messageLogger, filename, parserOptions);
        }

        void NurbsXmlParser::SubElementControlPointsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto controlPoints = std::make_shared<ControlPointImpl>();
            auto typedObject = std::static_pointer_cast<NurbsImpl>(object);                    
            // Setting the parent
            controlPoints->SetParent(object);
            _controlPointXmlParser->ParseElement(indexedElement, parserContext, controlPoints);
            auto controlPointsList = typedObject->GetWriterControlPoints();
            controlPointsList.push_back(controlPoints);
            typedObject->SetControlPoints(controlPointsList);
        }
        
        int NurbsXmlParser::SubElementControlPointsParser::GetMinOccur() 
        {
            return 2;
        }

        int NurbsXmlParser::SubElementControlPointsParser::GetMaxOccur() 
        {
            return -1;
        }

        bool NurbsXmlParser::SubElementControlPointsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__CONTROL_POINT ;
        }

        std::vector<std::string> NurbsXmlParser::SubElementControlPointsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__CONTROL_POINT
                    };
        }
        NurbsXmlParser::SubElementKnotsParser::SubElementKnotsParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _knotXmlParser = std::make_shared<KnotXmlParser>(messageLogger, filename, parserOptions);
        }

        void NurbsXmlParser::SubElementKnotsParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto knots = std::make_shared<KnotImpl>();
            auto typedObject = std::static_pointer_cast<NurbsImpl>(object);                    
            // Setting the parent
            knots->SetParent(object);
            _knotXmlParser->ParseElement(indexedElement, parserContext, knots);
            auto knotsList = typedObject->GetWriterKnots();
            knotsList.push_back(knots);
            typedObject->SetKnots(knotsList);
        }
        
        int NurbsXmlParser::SubElementKnotsParser::GetMinOccur() 
        {
            return 2;
        }

        int NurbsXmlParser::SubElementKnotsParser::GetMaxOccur() 
        {
            return -1;
        }

        bool NurbsXmlParser::SubElementKnotsParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__KNOT ;
        }

        std::vector<std::string> NurbsXmlParser::SubElementKnotsParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__KNOT
                    };
        }
  
        NurbsXmlParser::NurbsXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a ObjectControllerImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            ObjectControllerXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> ObjectControllerXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> ObjectControllerXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementCatalogReferenceParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementControllerParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        ObjectControllerXmlParser::SubElementCatalogReferenceParser::SubElementCatalogReferenceParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _catalogReferenceXmlParser = std::make_shared<CatalogReferenceXmlParser>(messageLogger, filename, parserOptions);
        }

        void ObjectControllerXmlParser::SubElementCatalogReferenceParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto catalogReference = std::make_shared<CatalogReferenceImpl>();
            auto typedObject = std::static_pointer_cast<ObjectControllerImpl>(object);                    
            // Setting the parent
            catalogReference->SetParent(object);
            _catalogReferenceXmlParser->ParseElement(indexedElement, parserContext, catalogReference);

            typedObject->SetCatalogReference(catalogReference);
            std::dynamic_pointer_cast<CatalogReferenceParserContext>(parserContext)->AddCatalogReference(std::dynamic_pointer_cast<ICatalogReference>(catalogReference));
        }
        
        int ObjectControllerXmlParser::SubElementCatalogReferenceParser::GetMinOccur() 
        {
            return 0;
        }

        int ObjectControllerXmlParser::SubElementCatalogReferenceParser::GetMaxOccur() 
        {
            return 1;
        }

        bool ObjectControllerXmlParser::SubElementCatalogReferenceParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__CATALOG_REFERENCE ;
        }

        std::vector<std::string> ObjectControllerXmlParser::SubElementCatalogReferenceParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__CATALOG_REFERENCE
                    };
        }
        ObjectControllerXmlParser::SubElementControllerParser::SubElementControllerParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _controllerXmlParser = std::make_shared<ControllerXmlParser>(messageLogger, filename, parserOptions);
        }

        void ObjectControllerXmlParser::SubElementControllerParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto controller = std::make_shared<ControllerImpl>();
            auto typedObject = std::static_pointer_cast<ObjectControllerImpl>(object);                    
            // Setting the parent
            controller->SetParent(object);
            _controllerXmlParser->ParseElement(indexedElement, parserContext, controller);

            typedObject->SetController(controller);
        }
        
        int ObjectControllerXmlParser::SubElementControllerParser::GetMinOccur() 
        {
            return 0;
        }

        int ObjectControllerXmlParser::SubElementControllerParser::GetMaxOccur() 
        {
            return 1;
        }

        bool ObjectControllerXmlParser::SubElementControllerParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__CONTROLLER ;
        }

        std::vector<std::string> ObjectControllerXmlParser::SubElementControllerParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__CONTROLLER
                    };
        }
  
        ObjectControllerXmlParser::ObjectControllerXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OffroadConditionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OffroadConditionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> OffroadConditionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeDuration: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeDuration(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OffroadConditionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__DURATION, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetDuration(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__DURATION, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__DURATION, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__DURATION, std::make_shared<AttributeDuration>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> OffroadConditionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        OffroadConditionXmlParser::OffroadConditionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OpenScenarioImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OpenScenarioXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> OpenScenarioXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> OpenScenarioXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementFileHeaderParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementOpenScenarioCategoryParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        OpenScenarioXmlParser::SubElementFileHeaderParser::SubElementFileHeaderParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _fileHeaderXmlParser = std::make_shared<FileHeaderXmlParser>(messageLogger, filename, parserOptions);
        }

        void OpenScenarioXmlParser::SubElementFileHeaderParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto fileHeader = std::make_shared<FileHeaderImpl>();
            auto typedObject = std::static_pointer_cast<OpenScenarioImpl>(object);                    
            // Setting the parent
            fileHeader->SetParent(object);
            _fileHeaderXmlParser->ParseElement(indexedElement, parserContext, fileHeader);

            typedObject->SetFileHeader(fileHeader);
        }
        
        int OpenScenarioXmlParser::SubElementFileHeaderParser::GetMinOccur() 
        {
            return 1;
        }

        int OpenScenarioXmlParser::SubElementFileHeaderParser::GetMaxOccur() 
        {
            return 1;
        }

        bool OpenScenarioXmlParser::SubElementFileHeaderParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__FILE_HEADER ;
        }

        std::vector<std::string> OpenScenarioXmlParser::SubElementFileHeaderParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__FILE_HEADER
                    };
        }
        OpenScenarioXmlParser::SubElementOpenScenarioCategoryParser::SubElementOpenScenarioCategoryParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _openScenarioCategoryXmlParser = std::make_shared<OpenScenarioCategoryXmlParser>(messageLogger, filename, parserOptions);
        }

        void OpenScenarioXmlParser::SubElementOpenScenarioCategoryParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto openScenarioCategory = std::make_shared<OpenScenarioCategoryImpl>();
            auto typedObject = std::static_pointer_cast<OpenScenarioImpl>(object);                    
            // Setting the parent
            openScenarioCategory->SetParent(object);
            _openScenarioCategoryXmlParser->ParseElement(indexedElement, parserContext, openScenarioCategory);

            typedObject->SetOpenScenarioCategory(openScenarioCategory);
        }
        
        int OpenScenarioXmlParser::SubElementOpenScenarioCategoryParser::GetMinOccur() 
        {
            return 1;
        }

        int OpenScenarioXmlParser::SubElementOpenScenarioCategoryParser::GetMaxOccur() 
        {
            return 1;
        }

        bool OpenScenarioXmlParser::SubElementOpenScenarioCategoryParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATIONS || 
                elementName == OSC_CONSTANTS::ELEMENT__CATALOG_LOCATIONS || 
                elementName == OSC_CONSTANTS::ELEMENT__CATALOG ;
        }

        std::vector<std::string> OpenScenarioXmlParser::SubElementOpenScenarioCategoryParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATIONS,
                OSC_CONSTANTS::ELEMENT__CATALOG_LOCATIONS,
                OSC_CONSTANTS::ELEMENT__CATALOG
                    };
        }
  
        OpenScenarioXmlParser::OpenScenarioXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OpenScenarioCategoryImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OpenScenarioCategoryXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlChoiceParser(messageLogger, filename, parserOptions) {}



        std::vector<std::shared_ptr<IElementParser>> OpenScenarioCategoryXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementScenarioDefinitionParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementCatalogDefinitionParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        OpenScenarioCategoryXmlParser::SubElementScenarioDefinitionParser::SubElementScenarioDefinitionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _scenarioDefinitionXmlParser = std::make_shared<ScenarioDefinitionXmlParser>(messageLogger, filename, parserOptions);
        }

        void OpenScenarioCategoryXmlParser::SubElementScenarioDefinitionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto scenarioDefinition = std::make_shared<ScenarioDefinitionImpl>();
            auto typedObject = std::static_pointer_cast<OpenScenarioCategoryImpl>(object);                    
            // Setting the parent
            scenarioDefinition->SetParent(object);
            _scenarioDefinitionXmlParser->ParseElement(indexedElement, parserContext, scenarioDefinition);

            typedObject->SetScenarioDefinition(scenarioDefinition);
        }
        
        int OpenScenarioCategoryXmlParser::SubElementScenarioDefinitionParser::GetMinOccur() 
        {
            return 1;
        }

        int OpenScenarioCategoryXmlParser::SubElementScenarioDefinitionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool OpenScenarioCategoryXmlParser::SubElementScenarioDefinitionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATIONS || 
                elementName == OSC_CONSTANTS::ELEMENT__CATALOG_LOCATIONS ;
        }

        std::vector<std::string> OpenScenarioCategoryXmlParser::SubElementScenarioDefinitionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__PARAMETER_DECLARATIONS,
                OSC_CONSTANTS::ELEMENT__CATALOG_LOCATIONS
                    };
        }
        OpenScenarioCategoryXmlParser::SubElementCatalogDefinitionParser::SubElementCatalogDefinitionParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _catalogDefinitionXmlParser = std::make_shared<CatalogDefinitionXmlParser>(messageLogger, filename, parserOptions);
        }

        void OpenScenarioCategoryXmlParser::SubElementCatalogDefinitionParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto catalogDefinition = std::make_shared<CatalogDefinitionImpl>();
            auto typedObject = std::static_pointer_cast<OpenScenarioCategoryImpl>(object);                    
            // Setting the parent
            catalogDefinition->SetParent(object);
            _catalogDefinitionXmlParser->ParseElement(indexedElement, parserContext, catalogDefinition);

            typedObject->SetCatalogDefinition(catalogDefinition);
        }
        
        int OpenScenarioCategoryXmlParser::SubElementCatalogDefinitionParser::GetMinOccur() 
        {
            return 1;
        }

        int OpenScenarioCategoryXmlParser::SubElementCatalogDefinitionParser::GetMaxOccur() 
        {
            return 1;
        }

        bool OpenScenarioCategoryXmlParser::SubElementCatalogDefinitionParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__CATALOG ;
        }

        std::vector<std::string> OpenScenarioCategoryXmlParser::SubElementCatalogDefinitionParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__CATALOG
                    };
        }
  
        OpenScenarioCategoryXmlParser::OpenScenarioCategoryXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlGroupParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OrientationImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OrientationXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> OrientationXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeH: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeH(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OrientationImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__H, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetH(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__H, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__H, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__H, std::make_shared<AttributeH>(_messageLogger, _filename, _parserOptions)));
            class AttributeP: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeP(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OrientationImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__P, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetP(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__P, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__P, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__P, std::make_shared<AttributeP>(_messageLogger, _filename, _parserOptions)));
            class AttributeR: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeR(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OrientationImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__R, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetR(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__R, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__R, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__R, std::make_shared<AttributeR>(_messageLogger, _filename, _parserOptions)));
            class AttributeType: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeType(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OrientationImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__TYPE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Enumeration Type
                        const auto kResult = ReferenceContext::GetFromLiteral(attributeValue);
                        if (kResult != ReferenceContext::UNKNOWN)
                        {
                            typedObject->SetType(attributeValue);
                        }
                        else
                        {
                            auto msg = FileContentMessage("Value '" + attributeValue + "' is not allowed.", ERROR, startMarker);
                            _messageLogger.LogMessage(msg);
                        }
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__TYPE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__TYPE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 0;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__TYPE, std::make_shared<AttributeType>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> OrientationXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        OrientationXmlParser::OrientationXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OverrideBrakeActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OverrideBrakeActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> OverrideBrakeActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeActive: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeActive(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideBrakeActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetActive(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<AttributeActive>(_messageLogger, _filename, _parserOptions)));
            class AttributeValue: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeValue(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideBrakeActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__VALUE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetValue(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<AttributeValue>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> OverrideBrakeActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        OverrideBrakeActionXmlParser::OverrideBrakeActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OverrideClutchActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OverrideClutchActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> OverrideClutchActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeActive: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeActive(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideClutchActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetActive(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<AttributeActive>(_messageLogger, _filename, _parserOptions)));
            class AttributeValue: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeValue(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideClutchActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__VALUE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetValue(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<AttributeValue>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> OverrideClutchActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        OverrideClutchActionXmlParser::OverrideClutchActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OverrideControllerValueActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OverrideControllerValueActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlAllParser(messageLogger, filename, parserOptions) {}


        std::map<std::string, std::shared_ptr<IAttributeParser>> OverrideControllerValueActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> OverrideControllerValueActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            result.push_back(std::make_shared<SubElementThrottleParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementBrakeParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementClutchParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementParkingBrakeParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementSteeringWheelParser>(_messageLogger, _filename, _parserOptions));
            result.push_back(std::make_shared<SubElementGearParser>(_messageLogger, _filename, _parserOptions));
            return result;
        }

        OverrideControllerValueActionXmlParser::SubElementThrottleParser::SubElementThrottleParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _overrideThrottleActionXmlParser = std::make_shared<OverrideThrottleActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void OverrideControllerValueActionXmlParser::SubElementThrottleParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto throttle = std::make_shared<OverrideThrottleActionImpl>();
            auto typedObject = std::static_pointer_cast<OverrideControllerValueActionImpl>(object);                    
            // Setting the parent
            throttle->SetParent(object);
            _overrideThrottleActionXmlParser->ParseElement(indexedElement, parserContext, throttle);

            typedObject->SetThrottle(throttle);
        }
        
        int OverrideControllerValueActionXmlParser::SubElementThrottleParser::GetMinOccur() 
        {
            return 1;
        }

        int OverrideControllerValueActionXmlParser::SubElementThrottleParser::GetMaxOccur() 
        {
            return 1;
        }

        bool OverrideControllerValueActionXmlParser::SubElementThrottleParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__THROTTLE ;
        }

        std::vector<std::string> OverrideControllerValueActionXmlParser::SubElementThrottleParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__THROTTLE
                    };
        }
        OverrideControllerValueActionXmlParser::SubElementBrakeParser::SubElementBrakeParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _overrideBrakeActionXmlParser = std::make_shared<OverrideBrakeActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void OverrideControllerValueActionXmlParser::SubElementBrakeParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto brake = std::make_shared<OverrideBrakeActionImpl>();
            auto typedObject = std::static_pointer_cast<OverrideControllerValueActionImpl>(object);                    
            // Setting the parent
            brake->SetParent(object);
            _overrideBrakeActionXmlParser->ParseElement(indexedElement, parserContext, brake);

            typedObject->SetBrake(brake);
        }
        
        int OverrideControllerValueActionXmlParser::SubElementBrakeParser::GetMinOccur() 
        {
            return 1;
        }

        int OverrideControllerValueActionXmlParser::SubElementBrakeParser::GetMaxOccur() 
        {
            return 1;
        }

        bool OverrideControllerValueActionXmlParser::SubElementBrakeParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__BRAKE ;
        }

        std::vector<std::string> OverrideControllerValueActionXmlParser::SubElementBrakeParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__BRAKE
                    };
        }
        OverrideControllerValueActionXmlParser::SubElementClutchParser::SubElementClutchParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _overrideClutchActionXmlParser = std::make_shared<OverrideClutchActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void OverrideControllerValueActionXmlParser::SubElementClutchParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto clutch = std::make_shared<OverrideClutchActionImpl>();
            auto typedObject = std::static_pointer_cast<OverrideControllerValueActionImpl>(object);                    
            // Setting the parent
            clutch->SetParent(object);
            _overrideClutchActionXmlParser->ParseElement(indexedElement, parserContext, clutch);

            typedObject->SetClutch(clutch);
        }
        
        int OverrideControllerValueActionXmlParser::SubElementClutchParser::GetMinOccur() 
        {
            return 1;
        }

        int OverrideControllerValueActionXmlParser::SubElementClutchParser::GetMaxOccur() 
        {
            return 1;
        }

        bool OverrideControllerValueActionXmlParser::SubElementClutchParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__CLUTCH ;
        }

        std::vector<std::string> OverrideControllerValueActionXmlParser::SubElementClutchParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__CLUTCH
                    };
        }
        OverrideControllerValueActionXmlParser::SubElementParkingBrakeParser::SubElementParkingBrakeParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _overrideParkingBrakeActionXmlParser = std::make_shared<OverrideParkingBrakeActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void OverrideControllerValueActionXmlParser::SubElementParkingBrakeParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto parkingBrake = std::make_shared<OverrideParkingBrakeActionImpl>();
            auto typedObject = std::static_pointer_cast<OverrideControllerValueActionImpl>(object);                    
            // Setting the parent
            parkingBrake->SetParent(object);
            _overrideParkingBrakeActionXmlParser->ParseElement(indexedElement, parserContext, parkingBrake);

            typedObject->SetParkingBrake(parkingBrake);
        }
        
        int OverrideControllerValueActionXmlParser::SubElementParkingBrakeParser::GetMinOccur() 
        {
            return 1;
        }

        int OverrideControllerValueActionXmlParser::SubElementParkingBrakeParser::GetMaxOccur() 
        {
            return 1;
        }

        bool OverrideControllerValueActionXmlParser::SubElementParkingBrakeParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__PARKING_BRAKE ;
        }

        std::vector<std::string> OverrideControllerValueActionXmlParser::SubElementParkingBrakeParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__PARKING_BRAKE
                    };
        }
        OverrideControllerValueActionXmlParser::SubElementSteeringWheelParser::SubElementSteeringWheelParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _overrideSteeringWheelActionXmlParser = std::make_shared<OverrideSteeringWheelActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void OverrideControllerValueActionXmlParser::SubElementSteeringWheelParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto steeringWheel = std::make_shared<OverrideSteeringWheelActionImpl>();
            auto typedObject = std::static_pointer_cast<OverrideControllerValueActionImpl>(object);                    
            // Setting the parent
            steeringWheel->SetParent(object);
            _overrideSteeringWheelActionXmlParser->ParseElement(indexedElement, parserContext, steeringWheel);

            typedObject->SetSteeringWheel(steeringWheel);
        }
        
        int OverrideControllerValueActionXmlParser::SubElementSteeringWheelParser::GetMinOccur() 
        {
            return 1;
        }

        int OverrideControllerValueActionXmlParser::SubElementSteeringWheelParser::GetMaxOccur() 
        {
            return 1;
        }

        bool OverrideControllerValueActionXmlParser::SubElementSteeringWheelParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__STEERING_WHEEL ;
        }

        std::vector<std::string> OverrideControllerValueActionXmlParser::SubElementSteeringWheelParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__STEERING_WHEEL
                    };
        }
        OverrideControllerValueActionXmlParser::SubElementGearParser::SubElementGearParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions)
        {
            _overrideGearActionXmlParser = std::make_shared<OverrideGearActionXmlParser>(messageLogger, filename, parserOptions);
        }

        void OverrideControllerValueActionXmlParser::SubElementGearParser::Parse(std::shared_ptr<IndexedElement>& indexedElement, std::shared_ptr<ParserContext>& parserContext, std::shared_ptr<BaseImpl> object)
        {
            auto gear = std::make_shared<OverrideGearActionImpl>();
            auto typedObject = std::static_pointer_cast<OverrideControllerValueActionImpl>(object);                    
            // Setting the parent
            gear->SetParent(object);
            _overrideGearActionXmlParser->ParseElement(indexedElement, parserContext, gear);

            typedObject->SetGear(gear);
        }
        
        int OverrideControllerValueActionXmlParser::SubElementGearParser::GetMinOccur() 
        {
            return 1;
        }

        int OverrideControllerValueActionXmlParser::SubElementGearParser::GetMaxOccur() 
        {
            return 1;
        }

        bool OverrideControllerValueActionXmlParser::SubElementGearParser::DoesMatch(std::string& elementName)
        {
            return
                elementName == OSC_CONSTANTS::ELEMENT__GEAR ;
        }

        std::vector<std::string> OverrideControllerValueActionXmlParser::SubElementGearParser::GetExpectedTagNames()
        {
            return {
                OSC_CONSTANTS::ELEMENT__GEAR
                    };
        }
  
        OverrideControllerValueActionXmlParser::OverrideControllerValueActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OverrideGearActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OverrideGearActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> OverrideGearActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeActive: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeActive(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideGearActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetActive(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<AttributeActive>(_messageLogger, _filename, _parserOptions)));
            class AttributeNumber: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeNumber(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideGearActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__NUMBER, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetNumber(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__NUMBER, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__NUMBER, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__NUMBER, std::make_shared<AttributeNumber>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> OverrideGearActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        OverrideGearActionXmlParser::OverrideGearActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OverrideParkingBrakeActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OverrideParkingBrakeActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> OverrideParkingBrakeActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeActive: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeActive(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideParkingBrakeActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetActive(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<AttributeActive>(_messageLogger, _filename, _parserOptions)));
            class AttributeValue: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeValue(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideParkingBrakeActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__VALUE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetValue(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<AttributeValue>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> OverrideParkingBrakeActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        OverrideParkingBrakeActionXmlParser::OverrideParkingBrakeActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OverrideSteeringWheelActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OverrideSteeringWheelActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> OverrideSteeringWheelActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeActive: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeActive(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideSteeringWheelActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetActive(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<AttributeActive>(_messageLogger, _filename, _parserOptions)));
            class AttributeValue: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeValue(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideSteeringWheelActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__VALUE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetValue(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<AttributeValue>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> OverrideSteeringWheelActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        OverrideSteeringWheelActionXmlParser::OverrideSteeringWheelActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

        /**
         * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
         * Filling a OverrideThrottleActionImpl instance from an xml tree.
         * 
         * @author RA Consulting OpenSCENARIO generation facility
        */
            OverrideThrottleActionXmlParser::SubElementParser::SubElementParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): XmlSequenceParser(messageLogger, filename, parserOptions) {}

        std::map<std::string, std::shared_ptr<IAttributeParser>> OverrideThrottleActionXmlParser::GetAttributeNameToAttributeParserMap()
        {
            std::map<std::string, std::shared_ptr<IAttributeParser>> result;

            class AttributeActive: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeActive(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideThrottleActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetActive(ParseBoolean(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__ACTIVE, std::make_shared<AttributeActive>(_messageLogger, _filename, _parserOptions)));
            class AttributeValue: public IAttributeParser, public XmlParserBase
            {
            public:
                AttributeValue(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions):XmlParserBase(messageLogger, filename, parserOptions) {}

                void Parse(Position& startPosition, Position& endPosition, Position& startValuePosition, std::string& attributeName, std::string& attributeValue, std::shared_ptr<BaseImpl> object) override
                {
                    Textmarker startMarker(startPosition.GetLine(), startPosition.GetColumn(), _filename);
                    Textmarker endMarker(endPosition.GetLine(), endPosition.GetColumn(), _filename);
                    Textmarker startValueMarker(startValuePosition.GetLine(), startValuePosition.GetColumn(), _filename);
                    auto typedObject = std::static_pointer_cast<OverrideThrottleActionImpl>(object);
                    if (IsParametrized(attributeValue))
                    {
                        typedObject->SetAttributeParameter(OSC_CONSTANTS::ATTRIBUTE__VALUE, StripDollarSign(attributeValue), startMarker); 
                    }
                    else
                    {
                    	
                        // Parse value
                        // Simple type
                        typedObject->SetValue(ParseDouble(attributeValue, startMarker));
                    }
                    typedObject->PutPropertyStartMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(startMarker));
                    typedObject->PutPropertyEndMarker(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<Textmarker>(endMarker));
                    
                }

                int GetMinOccur() override
                {
                    return 1;
                }
            };
            result.emplace(std::make_pair(OSC_CONSTANTS::ATTRIBUTE__VALUE, std::make_shared<AttributeValue>(_messageLogger, _filename, _parserOptions)));
            return result;
        }

        std::vector<std::shared_ptr<IElementParser>> OverrideThrottleActionXmlParser::SubElementParser::CreateParserList()
        {
            std::vector<std::shared_ptr<IElementParser>> result;
            return result;
        }

  
        OverrideThrottleActionXmlParser::OverrideThrottleActionXmlParser(IParserMessageLogger& messageLogger, std::string& filename, ParserOptions& parserOptions): 
        XmlComplexTypeParser(messageLogger, filename, parserOptions)
        {
            _subElementParser = std::make_shared<SubElementParser>(messageLogger, filename, parserOptions);
        }
        

    
    }
}
