import React, {PureComponent} from 'react';

export default class SystemLog extends PureComponent{

    render(){
        return(
            <div className="col-md-8 well tabcontent" id="system_log">
                <h1 className="page-header">
                    <small>System Log</small>
                </h1>
                <div className="table-responsive">
                    <fieldset className="log_field">
                        <select size="2" id="log_list">
                            <option id="option1_1" draggable="true">facebook</option>
                            <option id="option1_2" draggable="true">instagram</option>
                            <option id="option1_3" draggable="true">twitter</option>
                        </select>
                    </fieldset>
                </div>
            </div>
        );
    }
}
