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
package net.asam.openscenario.v1_0.impl;

import java.util.ArrayList;
import java.util.Date;
import java.util.Hashtable;
import java.util.List;
import net.asam.openscenario.api.IOpenScenarioFlexElement;
import net.asam.openscenario.api.KeyNotSupportedException;
import net.asam.openscenario.common.INamedReference;
import net.asam.openscenario.common.IParserMessageLogger;
import net.asam.openscenario.impl.BaseImpl;
import net.asam.openscenario.impl.NamedReferenceProxy;
import net.asam.openscenario.parser.ParserHelper;
import net.asam.openscenario.v1_0.api.IEntity;
import net.asam.openscenario.v1_0.api.IOrientation;
import net.asam.openscenario.v1_0.api.IRelativeObjectPosition;
import net.asam.openscenario.v1_0.common.OscConstants;

/**
 * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
 *
 * <p>Value class that implements IRelativeObjectPosition. With setter methods to fill the
 * properties.
 *
 * <ul>
 *   <li>getter methods for properties (implemented methods of IRelativeObjectPosition)
 *   <li>setter methods for properties
 *   <li>getChildren method to collect all children
 *   <li>clone function to make a deep copy
 *   <li>overrides from BaseImpl
 * </ul>
 *
 * @author RA Consulting OpenSCENARIO generation facility
 */
public class RelativeObjectPositionImpl extends BaseImpl
    implements IRelativeObjectPosition, Cloneable {
  protected static Hashtable<String, Class<?>> propertyToType = new Hashtable<String, Class<?>>();

  /** Filling the property to type map */
  static {
    propertyToType.put(OscConstants.ATTRIBUTE__ENTITY_REF, String.class);
    propertyToType.put(OscConstants.ATTRIBUTE__DX, Double.class);
    propertyToType.put(OscConstants.ATTRIBUTE__DY, Double.class);
    propertyToType.put(OscConstants.ATTRIBUTE__DZ, Double.class);
  }

  private NamedReferenceProxy<IEntity> entityRef;
  private Double dx;
  private Double dy;
  private Double dz;
  private IOrientation orientation;
  /** Default constructor */
  public RelativeObjectPositionImpl() {
    super();
    addAdapter(RelativeObjectPositionImpl.class, this);
    addAdapter(IRelativeObjectPosition.class, this);
  }

  public IOpenScenarioFlexElement getOpenScenarioFlexElement() {
    return this;
  }

  @Override
  public INamedReference<IEntity> getEntityRef() {
    return entityRef;
  }

  @Override
  public Double getDx() {
    return dx;
  }

  @Override
  public Double getDy() {
    return dy;
  }

  @Override
  public Double getDz() {
    return dz;
  }

  @Override
  public IOrientation getOrientation() {
    return orientation;
  }
  /**
   * Sets the value of model property entityRef
   *
   * @param entityRef from OpenSCENARIO class model specification: [Reference entity.]
   */
  public void setEntityRef(NamedReferenceProxy<IEntity> entityRef) {
    this.entityRef = entityRef;
  }
  /**
   * Sets the value of model property dx
   *
   * @param dx from OpenSCENARIO class model specification: [Relative position in the x axis, using
   *     the coordinate system of the reference entity.]
   */
  public void setDx(Double dx) {
    this.dx = dx;
  }
  /**
   * Sets the value of model property dy
   *
   * @param dy from OpenSCENARIO class model specification: [Relative position in the y axis, using
   *     the coordinate system of the reference entity.]
   */
  public void setDy(Double dy) {
    this.dy = dy;
  }
  /**
   * Sets the value of model property dz
   *
   * @param dz from OpenSCENARIO class model specification: [Relative position in the z axis, using
   *     the coordinate system of the reference entity.]
   */
  public void setDz(Double dz) {
    this.dz = dz;
  }
  /**
   * Sets the value of model property orientation
   *
   * @param orientation from OpenSCENARIO class model specification: [Orientation. The relative
   *     reference context refers to the orientation of the reference entity.]
   */
  public void setOrientation(IOrientation orientation) {
    this.orientation = orientation;
  }

  @Override
  public void resolveParameterInternal(
      IParserMessageLogger logger, String attributeKey, String parameterLiteralValue) {
    if (attributeKey.equals(OscConstants.ATTRIBUTE__ENTITY_REF)) {
      // Proxy
      NamedReferenceProxy<IEntity> proxy = new NamedReferenceProxy<IEntity>(parameterLiteralValue);
      entityRef = proxy;
      removeResolvedParameter(attributeKey);

    } else if (attributeKey.equals(OscConstants.ATTRIBUTE__DX)) {
      // Simple type
      dx = ParserHelper.parseDouble(logger, parameterLiteralValue, getTextmarker(attributeKey));
      removeResolvedParameter(attributeKey);

    } else if (attributeKey.equals(OscConstants.ATTRIBUTE__DY)) {
      // Simple type
      dy = ParserHelper.parseDouble(logger, parameterLiteralValue, getTextmarker(attributeKey));
      removeResolvedParameter(attributeKey);

    } else if (attributeKey.equals(OscConstants.ATTRIBUTE__DZ)) {
      // Simple type
      dz = ParserHelper.parseDouble(logger, parameterLiteralValue, getTextmarker(attributeKey));
      removeResolvedParameter(attributeKey);
    }
  }

  @Override
  public Class<?> getTypeFromAttributeName(String attributeKey) {
    return propertyToType.get(attributeKey);
  }

  /**
   * A list of all aggregated children (lists are flattened). This may be used for applying a
   * specific method for any child.
   *
   * @return a list with all children (as BaseImpl)
   */
  public List<BaseImpl> getChildren() {
    List<BaseImpl> result = new ArrayList<BaseImpl>();

    IOrientation orientation = null;
    orientation = getOrientation();
    if (orientation != null) {
      result.add((BaseImpl) orientation);
    }
    return result;
  }

  /**
   * Making a (deep) clone this object. This is useful and used for importing elements from
   * catalogs.
   *
   * @return a deep copy of the object.
   */
  public RelativeObjectPositionImpl clone() {
    RelativeObjectPositionImpl clonedObject = new RelativeObjectPositionImpl();
    cloneStartMarker(clonedObject);
    cloneEndMarker(clonedObject);
    cloneAttributeKeyToStartMarker(clonedObject);
    cloneAttributeKeyToEndMarker(clonedObject);
    cloneAttributeKeyToParameterNameMap(clonedObject);
    // clone attributes;
    // Proxy
    NamedReferenceProxy<IEntity> proxy = ((NamedReferenceProxy<IEntity>) getEntityRef()).clone();
    clonedObject.setEntityRef(proxy);
    proxy.setParent(clonedObject);
    // Simple type
    clonedObject.setDx(getDx());
    // Simple type
    clonedObject.setDy(getDy());
    // Simple type
    clonedObject.setDz(getDz());
    // clone children
    IOrientation orientation = null;
    orientation = getOrientation();
    if (orientation != null) {
      OrientationImpl clonedChild = ((OrientationImpl) orientation).clone();
      clonedObject.setOrientation(clonedChild);
      clonedChild.setParent(clonedObject);
    }
    return clonedObject;
  }

  // Implement the IOpenScenarioFlexElement interface

  @Override
  public String getStringProperty(String key) throws KeyNotSupportedException {
    // proxies and string attributes
    if (key == null) {
      throw new KeyNotSupportedException();
    }
    if (key.equals(OscConstants.ATTRIBUTE__ENTITY_REF)) {
      // Get the Proxy
      INamedReference<IEntity> entityRef = getEntityRef();
      return entityRef != null ? entityRef.getNameRef() : null;
    } else {
      throw new KeyNotSupportedException();
    }
  }

  @Override
  public Long getUnsignedIntProperty(String key) throws KeyNotSupportedException {
    throw new KeyNotSupportedException();
  }

  @Override
  public Integer getIntProperty(String key) throws KeyNotSupportedException {
    throw new KeyNotSupportedException();
  }

  @Override
  public Double getDoubleProperty(String key) throws KeyNotSupportedException {
    if (key == null) {
      throw new KeyNotSupportedException();
    }
    if (key.equals(OscConstants.ATTRIBUTE__DX)) {
      return getDx();
    } else if (key.equals(OscConstants.ATTRIBUTE__DY)) {
      return getDy();
    } else if (key.equals(OscConstants.ATTRIBUTE__DZ)) {
      return getDz();
    } else {
      throw new KeyNotSupportedException();
    }
  }

  @Override
  public Integer getUnsignedShortProperty(String key) throws KeyNotSupportedException {
    throw new KeyNotSupportedException();
  }

  @Override
  public Boolean getBooleanProperty(String key) throws KeyNotSupportedException {
    throw new KeyNotSupportedException();
  }

  @Override
  public Date getDateTimeProperty(String key) throws KeyNotSupportedException {
    throw new KeyNotSupportedException();
  }

  @Override
  public IOpenScenarioFlexElement getChildElement(String key) throws KeyNotSupportedException {
    if (key == null) {
      throw new KeyNotSupportedException();
    }
    if (key.equals(OscConstants.ELEMENT__ORIENTATION)) {
      return (IOpenScenarioFlexElement) getOrientation();
    } else {
      throw new KeyNotSupportedException();
    }
  }

  @Override
  public List<IOpenScenarioFlexElement> getListChildElement(String key)
      throws KeyNotSupportedException {
    throw new KeyNotSupportedException();
  }

  @Override
  public IOpenScenarioFlexElement getParentFlexElement() {
    return (IOpenScenarioFlexElement) getParent();
  }

  @Override
  public IOpenScenarioFlexElement getReferencedElement(String key, String name)
      throws KeyNotSupportedException {
    if (key == null) {
      throw new KeyNotSupportedException();
    }
    if (key.equals(OscConstants.ATTRIBUTE__ENTITY_REF)) {
      // Get the Proxy
      INamedReference<IEntity> entityRef = getEntityRef();
      return entityRef != null ? (IOpenScenarioFlexElement) entityRef.getTargetObject() : null;
    } else {
      throw new KeyNotSupportedException();
    }
  }

  @Override
  public String getEnumerationLiteral(String key) throws KeyNotSupportedException {
    throw new KeyNotSupportedException();
  }

  @Override
  public String getModelType() {
    return "RelativeObjectPosition";
  }
}
