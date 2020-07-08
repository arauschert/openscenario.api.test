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
package de.rac.openscenario.v1_0.impl;

import de.rac.openscenario.v1_0.api.ILaneOffsetAction;
import de.rac.openscenario.impl.BaseImpl;
import de.rac.openscenario.common.ILocator;
import de.rac.openscenario.common.IParserMessageLogger;
import de.rac.openscenario.v1_0.common.OscConstants;
import de.rac.openscenario.common.FileContentMessage;
import de.rac.openscenario.api.IOpenScenarioModelElement;
import de.rac.openscenario.api.IOpenScenarioFlexElement;
import de.rac.openscenario.api.KeyNotSupportedException;
import java.util.Date;
import java.lang.Cloneable;
import de.rac.openscenario.parser.ParserHelper;
import java.util.Hashtable;
import java.util.List;
import java.util.ArrayList;

import de.rac.openscenario.v1_0.api.ILaneOffsetActionDynamics;
import de.rac.openscenario.v1_0.api.ILaneOffsetTarget;


/**
 * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
 * <p>
 * Value class that implements ILaneOffsetAction. With setter methods to fill the properties.
 * <ul>
 * <li> getter methods for properties (implemented methods of ILaneOffsetAction)
 * <li> setter methods for properties
 * <li> getChildren method to collect all children
 * <li> clone function to make a deep copy
 * <li> overrides from BaseImpl
 * </ul>
 * 
 * @author RA Consulting OpenSCENARIO generation facility
*/
public class LaneOffsetActionImpl extends BaseImpl implements ILaneOffsetAction, Cloneable{
	
	/**
	 * Filling the property to type map
	 */
	 static{
		propertyToType.put(OscConstants.ATTRIBUTE__CONTINUOUS, Boolean.class);
	}
	
	private Boolean continuous;
	private ILaneOffsetActionDynamics laneOffsetActionDynamics;
	private ILaneOffsetTarget laneOffsetTarget;
	/**
	 * Default constructor
	 */
	public LaneOffsetActionImpl()
	{
		super();
		addAdapter(LaneOffsetActionImpl.class, this);
		addAdapter(ILaneOffsetAction.class, this);
		
	}
	@Override
	public Boolean getContinuous()
	{
		return continuous;
	}
	@Override
	public ILaneOffsetActionDynamics getLaneOffsetActionDynamics()
	{
		return laneOffsetActionDynamics;
	}
	@Override
	public ILaneOffsetTarget getLaneOffsetTarget()
	{
		return laneOffsetTarget;
	}
	/**
	 * Sets the value of model property continuous
	 * @param continuous from OpenSCENARIO class model specification: [If false, the action ends when the target lane is 
	 * reached. If true it does not end but has to be stopped.]
	 * 
	*/
	public  void setContinuous (Boolean continuous )
	{
		this.continuous = continuous;
	}
	/**
	 * Sets the value of model property laneOffsetActionDynamics
	 * @param laneOffsetActionDynamics from OpenSCENARIO class model specification: [Parameters defining the dynamics of the 
	 * LaneOffsetAction.]
	 * 
	*/
	public  void setLaneOffsetActionDynamics (ILaneOffsetActionDynamics laneOffsetActionDynamics )
	{
		this.laneOffsetActionDynamics = laneOffsetActionDynamics;
	}
	/**
	 * Sets the value of model property laneOffsetTarget
	 * @param laneOffsetTarget from OpenSCENARIO class model specification: [Parameters indicating if the lane offset is 
	 * defined relative to another entity or absolute to the current lane's center , line.]
	 * 
	*/
	public  void setLaneOffsetTarget (ILaneOffsetTarget laneOffsetTarget )
	{
		this.laneOffsetTarget = laneOffsetTarget;
	}

	@Override
	public  void resolveParameterInternal(IParserMessageLogger logger,String attributeKey, String parameterLiteralValue)
	{
		if (attributeKey.equals(OscConstants.ATTRIBUTE__CONTINUOUS))
		{
			// Simple type
			continuous = ParserHelper.parseBoolean(logger,parameterLiteralValue,getTextmarker(attributeKey));
			removeResolvedParameter(attributeKey);
				
	 	}
	}
	
	@Override
	public  Class<?> getTypeFromAttributeName(String attributeKey)
	{
		return propertyToType.get(attributeKey);
	}

	/**
	 * A list of all aggregated children (lists are flattened). This may be used for applying a specific 
	 * method for any child.
	 * @return a list with all children (as BaseImpl)
	 */
	public List<BaseImpl> getChildren()
	{
		List<BaseImpl> result = new ArrayList<BaseImpl>();
		
			ILaneOffsetActionDynamics laneOffsetActionDynamics = null;
			laneOffsetActionDynamics =  getLaneOffsetActionDynamics();
			if (laneOffsetActionDynamics != null)
			{
				result.add((BaseImpl) laneOffsetActionDynamics);
			}	
			ILaneOffsetTarget laneOffsetTarget = null;
			laneOffsetTarget =  getLaneOffsetTarget();
			if (laneOffsetTarget != null)
			{
				result.add((BaseImpl) laneOffsetTarget);
			}	
		return result;
	}
	
	/**
	 * Making a (deep) clone this object. This is useful and used for importing elements from catalogs.
	 * @return a deep copy of the object.
	 */
	public LaneOffsetActionImpl clone()
	{
		LaneOffsetActionImpl clonedObject = new LaneOffsetActionImpl();
		cloneStartMarker(clonedObject);
		cloneEndMarker(clonedObject);
		cloneAttributeKeyToStartMarker(clonedObject);
		cloneAttributeKeyToEndMarker(clonedObject);
		cloneAttributeKeyToParameterNameMap(clonedObject);
		// clone attributes;
		// Simple type
		clonedObject.setContinuous(getContinuous());		
		// clone children
		ILaneOffsetActionDynamics laneOffsetActionDynamics = null;
		laneOffsetActionDynamics =  getLaneOffsetActionDynamics();
		if (laneOffsetActionDynamics != null)
		{
			LaneOffsetActionDynamicsImpl clonedChild = ((LaneOffsetActionDynamicsImpl) laneOffsetActionDynamics).clone();
			clonedObject.setLaneOffsetActionDynamics(clonedChild);
			clonedChild.setParent(clonedObject);
		}	
		ILaneOffsetTarget laneOffsetTarget = null;
		laneOffsetTarget =  getLaneOffsetTarget();
		if (laneOffsetTarget != null)
		{
			LaneOffsetTargetImpl clonedChild = ((LaneOffsetTargetImpl) laneOffsetTarget).clone();
			clonedObject.setLaneOffsetTarget(clonedChild);
			clonedChild.setParent(clonedObject);
		}	
		return clonedObject;
	}
  
  // Implement the IOpenScenarioFlexElement interface

  @Override
  public String getStringProperty(String key) throws KeyNotSupportedException
  {
	// proxies and string attributes 
	throw new KeyNotSupportedException();
  }
  
  @Override
  public Long getUnsignedIntProperty(String key) throws KeyNotSupportedException
  {
	throw new KeyNotSupportedException();
  		
  }  
  
  @Override
  public Integer getIntProperty(String key) throws KeyNotSupportedException
  {
	throw new KeyNotSupportedException();
  		
  }
 
  @Override
  public Double getDoubleProperty(String key) throws KeyNotSupportedException
  {
	throw new KeyNotSupportedException();
  		
  }
  
  @Override
  public Integer getUnsignedShortProperty(String key) throws KeyNotSupportedException
  {
	throw new KeyNotSupportedException();
  	
  }
 
  @Override
  public Boolean getBooleanProperty(String key) throws KeyNotSupportedException
  {
	if (key == null)
	{
		throw new KeyNotSupportedException();
	}
	if (key.equals(OscConstants.ATTRIBUTE__CONTINUOUS))
	{
		return getContinuous();
	}else 
	{
		throw new KeyNotSupportedException();
	}
  	
  }
   
  @Override
  public Date getDateTimeProperty(String key) throws KeyNotSupportedException
  {
 	throw new KeyNotSupportedException();

  }
 
  @Override
  public IOpenScenarioFlexElement getChildElement(String key) throws KeyNotSupportedException
  {
	if (key == null)
	{
		throw new KeyNotSupportedException();
	}
	if (key.equals(OscConstants.ELEMENT__LANE_OFFSET_ACTION_DYNAMICS))
	{
		return (IOpenScenarioFlexElement) getLaneOffsetActionDynamics();
	}else 
	if (key.equals(OscConstants.ELEMENT__LANE_OFFSET_TARGET))
	{
		return (IOpenScenarioFlexElement) getLaneOffsetTarget();
	}else 
	{
		throw new KeyNotSupportedException();
	}
  }
 
  @Override
  public List<IOpenScenarioFlexElement> getListChildElement(String key) throws KeyNotSupportedException
  {
	throw new KeyNotSupportedException();
  }
   
  @Override
  public IOpenScenarioFlexElement getParentFlexElement()
  {
   	return (IOpenScenarioFlexElement) getParent();
  }
  
  @Override
  public IOpenScenarioFlexElement getReferencedElement(String key, String name) throws KeyNotSupportedException
  {
	throw new KeyNotSupportedException();
  }
  
  @Override 
  public String getEnumerationLiteral(String key) throws KeyNotSupportedException
  {
	throw new KeyNotSupportedException();
  }
  
  @Override
  public String getModelType()
  {
  	return "LaneOffsetAction";
  }
 	
}

